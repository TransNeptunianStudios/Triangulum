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

Animator AnimationFactory::asteroidDeathAnimation()
{
    Animator animation;
    animation.coordList.push_back({1, 1});
    animation.coordList.push_back({2, 1});
    animation.coordList.push_back({3, 1});
    animation.style = AS_RUN_ONCE;
    animation.timePerFrame = 1000.0/3.0;
    return animation;
}

Animator AnimationFactory::asteroidBossDeathAnimation()
{
    Animator animation;
    animation.coordList.push_back({7, 3, 96});
    animation.coordList.push_back({7, 6, 96});
    animation.coordList.push_back({10, 0, 96});
    animation.coordList.push_back({10, 3, 96});
    animation.coordList.push_back({10, 6, 96});
    animation.style = AS_RUN_ONCE;
    animation.timePerFrame = 1500.0/5.0;
    return animation;
}
