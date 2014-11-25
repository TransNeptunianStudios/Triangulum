#ifndef PICKUP_H
#define PICKUP_H

#include "entityx/Entity.h"

enum PickUpType
{
   // Pick ups for gun
   GUN_PICK_UP = 0,
   PUT_DOUBLE_GUN,

   // Pick ups for bullet
   BULLET_PICK_UP = 100,

   // Pick ups for health
   HEALTH_PICK_UP = 200,
   PUT_ONE_HEALTH,
};

struct PickUp : public entityx::Component<PickUp>
{
   PickUp(PickUpType put);

   PickUpType pickUpType;
};

#endif // PICKUP_H
