#include "systems/AnimationSystem.h"
#include "components/Animation.h"
#include "components/Motion.h"

using namespace entityx;

AnimationSystem::AnimationSystem()
{
}

void AnimationSystem::update(EntityManager &entities,
                             EventManager &events,
                             double dt)
{
   Animation::Handle animation;
   Motion::Handle motion;
   for (Entity entity : entities.entities_with_components(animation, motion))
   {
      animation->pAnimatible->animate(motion->velocity, dt);
   }
}
