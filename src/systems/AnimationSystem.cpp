#include "systems/AnimationSystem.h"
#include "components/Animation.h"
#include "components/Display.h"
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
   AnimationContainer::Handle animationContainer;
   Display::Handle display;
   for (entityx::Entity entity : entities.entities_with_components(animationContainer, display))
   {
      for (auto& p : animationContainer->getAnimations())
      {
         Animator& animator(p.second.second);

         if (animator.elapsedTime > animator.timePerFrame)
         {
            if (animator.currentIndex < animator.coordList.size()-1)
            {
               animator.currentIndex++;
               animator.elapsedTime = 0.0;
            }
            else if (animator.style == AS_LOOP)
            {
               animator.currentIndex = 0;
               animator.elapsedTime = 0.0;
            }
         }
         else
         {
            animator.elapsedTime += dt;
         }

         display->coord = animator.coordList[animator.currentIndex];
      }
   }

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
