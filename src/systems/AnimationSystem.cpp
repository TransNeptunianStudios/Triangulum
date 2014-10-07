#include "systems/AnimationSystem.h"

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
}
