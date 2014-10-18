#include "components/Health.h"

Health::Health()
: health(0)
, invulnerableTime(0.0)
{
}

Health::Health(long _health)
: health(_health)
, invulnerableTime(0.0)
{
}

Health::Health(long _health, double _invulnerableTime)
: health(_health)
, invulnerableTime(_invulnerableTime)
{
}

bool Health::isInvulnerable() const
{
   return invulnerableTime > 0.0;
}
