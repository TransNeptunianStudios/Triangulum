#ifndef IANIMATIBLE_H
#define IANIMATIBLE_H

#include "utils/Vector2.h"

class IAnimatible
{
public:

   virtual ~IAnimatible() {}

   virtual void animate(const Vector2 velocity, double dt) = 0;

};

#endif // IANIMATIBLE_H
