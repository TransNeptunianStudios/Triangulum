#include "AnimationFactory.h"

AnimationFactory::AnimationFactory()
{
}

DeathAnimation AnimationFactory::spaceShipDeathAnimation()
{
   DeathAnimation animation(DestroyedDeathAnimation);
   animation.coordList.push_back({0, 2});
   animation.coordList.push_back({1, 2});
   animation.coordList.push_back({2, 2});
   animation.coordList.push_back({3, 2});
   animation.coordList.push_back({4, 2});
   animation.coordList.push_back({999, 999});
   animation.type = AT_RUN_ONCE;
   animation.timePerFrame = 1000.0/6.0;
   return animation;
}

MovementAnimation AnimationFactory::spaceShipIdleAnimation()
{
   MovementAnimation animation(IdleMovementAnimation);
   animation.coordList.push_back({0, 0});
   animation.coordList.push_back({1, 0});
   animation.type = AT_LOOP;
   animation.timePerFrame = 1000.0/2.0;
   return animation;
}

MovementAnimation AnimationFactory::spaceShipTurnLeftAnimation()
{
   MovementAnimation animation(LeftMovementAnimation);
   animation.coordList.push_back({0, 3});
   animation.coordList.push_back({1, 3});
   animation.coordList.push_back({2, 3});
   animation.type = AT_RUN_ONCE;
   animation.timePerFrame = 1000.0/3.0;
   return animation;
}

MovementAnimation AnimationFactory::spaceShipTurnRightAnimation()
{
   MovementAnimation animation(RightMovementAnimation);
   animation.coordList.push_back({0, 4});
   animation.coordList.push_back({1, 4});
   animation.coordList.push_back({2, 4});
   animation.type = AT_RUN_ONCE;
   animation.timePerFrame = 1000.0/3.0;
   return animation;
}
