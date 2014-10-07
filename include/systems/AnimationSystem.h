#ifndef ANIMATIONSYSTEM_H
#define ANIMATIONSYSTEM_H

#include "entityx/System.h"
#include "components/Animation.h"
#include "components/Display.h"

class AnimationSystem : public entityx::System<AnimationSystem>
{
public:

   AnimationSystem();

   void update(entityx::EntityManager& entities,
               entityx::EventManager& events,
               double dt);

   template<class AnimationT>
   void updateAnimation(entityx::EntityManager& entities, double dt)
   {
      typename AnimationT::Handle animation;
      Display::Handle display;
      for (entityx::Entity entity : entities.entities_with_components(animation, display))
      {
         if (animation->elapsedTime > animation->timePerFrame)
         {
            if (animation->currentIndex < animation->coordList.size()-1)
            {
               animation->currentIndex++;
               animation->elapsedTime = 0.0;
            }
            else if (animation->type == AT_LOOP)
            {
               animation->currentIndex = 0;
            }
         }
         else
         {
            animation->elapsedTime += dt;
         }

         display->coord = animation->coordList[animation->currentIndex];
      }
   }
};

#endif // ANIMATIONSYSTEM_H
