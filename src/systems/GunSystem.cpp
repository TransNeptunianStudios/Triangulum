#include "systems/GunSystem.h"
#include "systems/Events.h"
#include "components/Position.h"
#include "components/Gun.h"
#include "utils/Math.h"
#include "EntityCreator.h"

using namespace entityx;

GunSystem::GunSystem()
{
}

void GunSystem::update(EntityManager &entities,
                       EventManager &events,
                       double dt)
{
   Position::Handle position;
   Gun::Handle gun;
   for (Entity entity : entities.entities_with_components(position, gun))
   {
      if (gun->isMainFirePressed && !gun->wasMainFirePressed)
      {
         auto initVelocity = sf::Vector2f(200.0*gun->direction.x,
                                          200.0*gun->direction.y);

         auto bulletPosition = *position.get();

         bulletPosition.heading = math::angleBetween(gun->direction,
                                                     sf::Vector2f(0.0, 1.0));

         BulletCreator(entity.id(),
                       position->position,
                       initVelocity,
                       gun->bulletType).create(entities.create());

         events.emit<EvPlaySound>(GUN_SHOOT);
      }

      gun->wasMainFirePressed = gun->isMainFirePressed;
   }
}
