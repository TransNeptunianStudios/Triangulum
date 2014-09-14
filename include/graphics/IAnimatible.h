#ifndef IANIMATIBLE_H
#define IANIMATIBLE_H

#include <memory>

#include "utils/Vector2.h"

class IAnimatible
{
public:

   virtual ~IAnimatible() {}

   virtual void animate(const Vector2 velocity, double dt) = 0;
};

typedef std::shared_ptr<IAnimatible> IAnimatibleSP;

#endif // IANIMATIBLE_H
