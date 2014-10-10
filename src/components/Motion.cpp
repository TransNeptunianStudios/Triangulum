#include "components/Motion.h"

Motion::Motion()
: velocity()
, rotation(0.0)
{
}

Motion::Motion(const Vector2 _velocity)
: velocity(_velocity)
, rotation(0.0)
{
}

Motion::Motion(const Vector2 _velocity, double _rotation)
: velocity(_velocity)
, rotation(_rotation)
{
}
