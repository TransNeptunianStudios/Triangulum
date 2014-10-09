#include "components/Animation.h"

Animator::Animator()
: elapsedTime(0.0)
, timePerFrame(0.0)
, style(AS_RUN_ONCE)
, coordList()
, currentIndex(0)
{
}

AnimationContainer::AnimationContainer()
: m_registeredAnimations()
, m_activeAnimations()
{
}

void AnimationContainer::addAnimation(const AnimationId& id, const Animator& animator)
{
   m_registeredAnimations[id] = animator;
}

void AnimationContainer::setAnimation(const AnimationId& id)
{
   AnimationMap::iterator animationIt = m_registeredAnimations.find(id);

   if (animationIt != end(m_registeredAnimations))
   {
      ActiveAnimatorMap::iterator activeAnimationIt = m_activeAnimations.find(id.first);

      if (activeAnimationIt != end(m_activeAnimations))
      {
         if (activeAnimationIt->second.first != id.second)
         {
            m_activeAnimations[id.first] = ActiveAnimator(id.second, animationIt->second);
         }
      }
      else
      {
         m_activeAnimations[id.first] = ActiveAnimator(id.second, animationIt->second);
      }
   }
}

void AnimationContainer::resetAnimation(AnimationType type)
{
   ActiveAnimatorMap::iterator it = m_activeAnimations.find(type);

   if (it != end(m_activeAnimations))
   {
      m_activeAnimations.erase(it);
   }
}

AnimationContainer::ActiveAnimatorMap& AnimationContainer::getAnimations()
{
   return m_activeAnimations;
}
