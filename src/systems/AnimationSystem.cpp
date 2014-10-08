#include "systems/AnimationSystem.h"
#include "components/Health.h"
#include "components/SpaceShip.h"

using namespace entityx;

AnimationSystem::AnimationSystem()
{
}

void AnimationSystem::update(EntityManager &entities,
                             EventManager &events,
                             double dt)
{
   updateAnimation<DeathAnimation>(entities, dt);
   updateAnimation<MovementAnimation>(entities, dt);

   Display::Handle display;
   Health::Handle health;
   SpaceShip::Handle spaceShip;
   for (entityx::Entity entity : entities.entities_with_components(display, health, spaceShip))
   {
      if (health->isInvulnerable())
      {
         if (health->timeSinceBlink > 100.0)
         {
            health->isOff = !health->isOff;
            health->timeSinceBlink = 0.0;
         }
         else
         {
            health->timeSinceBlink += dt;
         }

         if (health->isOff)
         {
            display->coord = SpriteSheetCoordinate(999, 999);
         }
      }
   }
}
