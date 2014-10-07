#ifndef ANIMATIONFACTORY_H
#define ANIMATIONFACTORY_H

#include "components/Animation.h"

class AnimationFactory
{
public:

   AnimationFactory();

   static DeathAnimation spaceShipDeathAnimation();

   static MovementAnimation spaceShipIdleAnimation();

   static MovementAnimation spaceShipTurnLeftAnimation();

   static MovementAnimation spaceShipTurnRightAnimation();
};

#endif // ANIMATIONFACTORY_H
