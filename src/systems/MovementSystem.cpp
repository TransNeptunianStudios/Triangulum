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
   for (Entity entity : entities.entities_with_components(motion, position))
   {
        sf::Vector2f newPos(position->position.x + motion->velocity.x * dt / 1000.0,
                            position->position.y + motion->velocity.y * dt / 1000.0);

        // Players are not allowed outside the screen
        if(    entity.has_component<PlayerControl>()
            && !isOnScreen(newPos))
            continue;

        position->position.x = newPos.x;
        position->position.y = newPos.y;

        position->heading += motion->rotation * dt / 1000.0;
    }

}

bool MovementSystem::isOnScreen(sf::Vector2f position) const
{
    return  position.x > 0.f
            && position.x < ScreenSize().width()
            && position.y > 0.f
            && position.y < ScreenSize().height();
}
