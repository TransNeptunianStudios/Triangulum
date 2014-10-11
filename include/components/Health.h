#ifndef HEALTH_H
#define HEALTH_H

#include "entityx/Entity.h"

struct Health : public entityx::Component<Health>
{
   Health(long _health);

   bool isInvulnerable() const;

   long health;

   double invulnerableTime;
};

#endif // HEALTH_H
