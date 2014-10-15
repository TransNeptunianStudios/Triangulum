#include "components/Motion.h"

Motion::Motion()
: velocity()
, rotation(0.0)
{
}

Motion::Motion(const sf::Vector2f _velocity)
: velocity(_velocity)
, rotation(0.0)
{
}

Motion::Motion(const sf::Vector2f _velocity, double _rotation)
: velocity(_velocity)
, rotation(_rotation)
{
}
