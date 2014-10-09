#include "AnimationFactory.h"

AnimationFactory::AnimationFactory()
{
}

Animator AnimationFactory::spaceShipDeathAnimation()
{
   Animator animation;
   animation.coordList.push_back({0, 2});
   animation.coordList.push_back({1, 2});
   animation.coordList.push_back({2, 2});
   animation.coordList.push_back({3, 2});
   animation.coordList.push_back({4, 2});
   animation.coordList.push_back({999, 999});
   animation.style = AS_RUN_ONCE;
   animation.timePerFrame = 1000.0/6.0;
   return animation;
}

Animator AnimationFactory::spaceShipIdleAnimation()
{
   Animator animation;
   animation.coordList.push_back({0, 0});
   animation.coordList.push_back({1, 0});
   animation.style = AS_LOOP;
   animation.timePerFrame = 200.0/2.0;
   return animation;
}

Animator AnimationFactory::spaceShipTurnLeftAnimation()
{
   Animator animation;
   animation.coordList.push_back({0, 3});
   animation.coordList.push_back({1, 3});
   animation.coordList.push_back({2, 3});
   animation.style = AS_RUN_ONCE;
   animation.timePerFrame = 1000.0/3.0;
   return animation;
}

Animator AnimationFactory::spaceShipTurnRightAnimation()
{
   Animator animation;
   animation.coordList.push_back({0, 4});
   animation.coordList.push_back({1, 4});
   animation.coordList.push_back({2, 4});
   animation.style = AS_RUN_ONCE;
   animation.timePerFrame = 1000.0/3.0;
   return animation;
}
