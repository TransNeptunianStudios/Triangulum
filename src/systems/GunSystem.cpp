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
         auto initVelocity = sf::Vector2f(500.0*gun->direction.x,
                                          500.0*gun->direction.y);

         auto bulletPosition = *position.get();

         bulletPosition.heading = math::angleBetween(sf::Vector2f(0.0, -1.0),
                                                     gun->direction);

         BulletCreator(entity.id(),                       
                       initVelocity,
                       bulletPosition.position,
                       bulletPosition.heading,
                       gun->bulletType).create(entities.create());

         events.emit<EvPlaySound>(GUN_SHOOT);
      }

      gun->wasMainFirePressed = gun->isMainFirePressed;
   }
}
