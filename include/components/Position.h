#ifndef POSITION_H
#define POSITION_H

#include "entityx/Entity.h"
#include "utils/Vector2.h"

struct Position : public entityx::Component<Position>
{
   Position();

   Position(const Vector2 &_position);

   Position(const Vector2 &_position, double _heading);

   Vector2 position;

   double heading;
};

#endif
