#include "systems/AnimationSystem.h"
#include "components/State.h"
#include "components/Motion.h"

using namespace entityx;

AnimationSystem::AnimationSystem()
{
}

void AnimationSystem::update(EntityManager &entities,
                             EventManager &events,
                             double dt)
{
   State::Handle animation;
   Motion::Handle motion;
   for (Entity entity : entities.entities_with_components(animation, motion))
   {
      animation->spAnimatible->animate(motion->velocity, dt);
   }
}
