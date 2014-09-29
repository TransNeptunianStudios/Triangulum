#include "systems/MovementSystem.h"
#include "components/PlayerControl.h"
#include "components/Motion.h"
#include "components/Position.h"

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
   Vector2 newPos;
   for (Entity entity : entities.entities_with_components(motion, position))
   {
        newPos = Vector2(position->position.x() + motion->velocity.x() * dt / 1000.0,
                                  position->position.y() + motion->velocity.y() * dt / 1000.0);

        // Players are not allowed outside the screen
        if(    entity.has_component<PlayerControl>()
            && !isOnScreen(newPos))
            continue;

        position->position.x() = newPos.x();
        position->position.y() = newPos.y();
    }

}

bool MovementSystem::isOnScreen(Vector2 position) const
{
    return  position.x() > 0.f
            && position.x() < ScreenSize().width()
            && position.y() > 0.f
            && position.y() < ScreenSize().height();
}
