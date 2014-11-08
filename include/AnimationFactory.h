#ifndef ANIMATIONFACTORY_H
#define ANIMATIONFACTORY_H

#include "components/Animation.h"

class AnimationFactory
{
public:

   AnimationFactory();

   static Animator spaceShipDeathAnimation();

   static Animator spaceShipIdleAnimation();

   static Animator spaceShipTurnLeftAnimation();

   static Animator spaceShipTurnRightAnimation();

   static Animator asteroidDeathAnimation();

   static Animator asteroidBossDeathAnimation();

   static Animator scoutIdleAnimation();

   static Animator scoutDeathAnimation();

   static Animator mineIdleAnimation();
};

#endif // ANIMATIONFACTORY_H
