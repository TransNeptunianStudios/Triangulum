#ifndef HEALTH_H
#define HEALTH_H

#include "entityx/Entity.h"

struct Health : public entityx::Component<Health>
{
   Health(long _health);

   bool isInvulnerable() const;

   long health;

   double invulnerableTime;

   double timeSinceBlink;

   bool isOff;
};

#endif // HEALTH_H
