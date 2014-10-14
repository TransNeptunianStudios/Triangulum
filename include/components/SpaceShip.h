#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "entityx/Entity.h"

struct SpaceShip : public entityx::Component<SpaceShip>
{
   SpaceShip(int score);

   int score;
};

#endif // SPACESHIP_H
