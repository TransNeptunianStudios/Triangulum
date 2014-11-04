#include "systems/GunSystem.h"
#include "systems/Events.h"
#include "components/Position.h"
#include "components/Gun.h"
#include "components/Enemy.h"
#include "components/SpaceShip.h"
#include "utils/TMath.h"
#include "EntityCreator.h"

#include "SFML/Graphics/Color.hpp"

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

         bulletPosition.heading = math::angleBetween(gun->direction);

         // Enemies have evil red shoots,
         // our hero have green, star wars style
         // Civilians have white.
         auto color = sf::Color();
         if(entity.has_component<Enemy>())
             color = sf::Color(255, 0, 0);
         else if(entity.has_component<SpaceShip>())
             color = sf::Color(0, 255, 0);

         BulletCreator(entity.id(),                       
                       initVelocity,
                       bulletPosition.position,
                       bulletPosition.heading,
                       gun->bulletType,
                       color).create(entities.create());

         events.emit<EvPlaySound>(GUN_SHOOT);
      }

      gun->wasMainFirePressed = gun->isMainFirePressed;
   }
}
