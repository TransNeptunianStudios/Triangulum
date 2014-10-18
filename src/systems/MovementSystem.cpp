#include "systems/MovementSystem.h"
#include "components/PlayerControl.h"
#include "components/Motion.h"
#include "components/Position.h"
#include "components/Volume.h"
#include "components/Animation.h"
#include "components/DeathSentence.h"
#include "ScreenSize.h"

using namespace entityx;

MovementSystem::MovementSystem()
{
}

void MovementSystem::update(EntityManager &entities,
                            EventManager &events,
                            double dt)
{
   Motion::Handle motion;
   Position::Handle position;
   for (Entity entity : entities.entities_with_components(motion, position))
   {
      sf::Vector2f newPos(position->position.x + motion->velocity.x * dt / 1000.0,
                          position->position.y + motion->velocity.y * dt / 1000.0);

      // Players are not allowed outside the screen
      if (entity.has_component<PlayerControl>() && !isOnScreen(newPos, entity))
      {
         continue;
      }

      position->position.x = newPos.x;
      position->position.y = newPos.y;

      position->heading += motion->rotation * dt / 1000.0;

      if (entity.has_component<AnimationContainer>() && !entity.has_component<DeathSentence>())
      {
         AnimationContainer* pAC = entity.component<AnimationContainer>().get();
         updateAnimation(pAC, motion->velocity);
      }
    }
}

bool MovementSystem::isOnScreen(sf::Vector2f position, Entity& entity) const
{
    // Until we get more hitboxes this will do
    auto hitBox  = entity.component<Volume>()->m_boxes.front().getRect();

    return position.x - hitBox.width/2 > 0.f
    && position.x + hitBox.width/2 < ScreenSize().width()
    && position.y - hitBox.height/2 > 0.f
    && position.y + hitBox.height/2 < ScreenSize().height();
}

void MovementSystem::updateAnimation(AnimationContainer *pAC,
                                     const sf::Vector2f &velocity)
{
   if (velocity.x > 0.1f)
   {
      pAC->setAnimation(AnimationId(AT_Movement, RightMovementAnimation));

   }
   else if (velocity.x < -0.1f)
   {
      pAC->setAnimation(AnimationId(AT_Movement, LeftMovementAnimation));
   }
   else
   {
      pAC->setAnimation(AnimationId(AT_Movement, IdleMovementAnimation));
   }
}
