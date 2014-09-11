#include "systems/MovementSystem.h"
#include "components/Motion.h"
#include "components/Position.h"

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
      position->position.x() += motion->velocity.x() * dt / 1000.0;
      position->position.y() += motion->velocity.y() * dt / 1000.0;
   }
}
