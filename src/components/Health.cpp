#include "components/Health.h"

Health::Health(long _health)
: health(_health)
, invulnerableTime(0.0)
, timeSinceBlink(0.0)
, isOff(true)
{
}

bool Health::isInvulnerable() const
{
   return invulnerableTime > 0.0;
}
