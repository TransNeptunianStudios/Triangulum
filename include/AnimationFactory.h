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
};

#endif // ANIMATIONFACTORY_H
