#include "AnimationFactory.h"

AnimationFactory::AnimationFactory()
{
}

DeathAnimation AnimationFactory::spaceShipDeathAnimation()
{
   DeathAnimation animation;
   animation.coordList.push_back({0, 2});
   animation.coordList.push_back({1, 2});
   animation.coordList.push_back({2, 2});
   animation.coordList.push_back({3, 2});
   animation.coordList.push_back({4, 2});
   animation.coordList.push_back({999, 999});
   animation.type = AT_RUN_ONCE;
   animation.timePerFrame = 1000.0/5.0;
   return animation;
}
