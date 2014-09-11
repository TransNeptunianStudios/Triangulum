#ifndef MOTION_H
#define MOTION_H

#include "entityx/Entity.h"
#include "utils/Vector2.h"

struct Motion : public entityx::Component<Motion>
{
   Motion();

   Motion(const Vector2 _velocity);

   Vector2 velocity;
};

#endif
