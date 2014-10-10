#ifndef MOTION_H
#define MOTION_H

#include "entityx/Entity.h"
#include "utils/Vector2.h"

struct Motion : public entityx::Component<Motion>
{
   Motion();

   Motion(const Vector2 _velocity);

   Motion(const Vector2 _velocity,
          double _rotation);

   Vector2 velocity;

   double rotation;
};

#endif
