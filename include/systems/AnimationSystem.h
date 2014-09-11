#ifndef ANIMATIONSYSTEM_H
#define ANIMATIONSYSTEM_H

#include "entityx/System.h"

class AnimationSystem : public entityx::System<AnimationSystem>
{
public:

   AnimationSystem();

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);
};

#endif // ANIMATIONSYSTEM_H
