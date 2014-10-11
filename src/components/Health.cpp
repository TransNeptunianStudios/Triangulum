#include "components/Health.h"

Health::Health(long _health)
: health(_health)
, invulnerableTime(0.0)
{
}

bool Health::isInvulnerable() const
{
   return invulnerableTime > 0.0;
}
