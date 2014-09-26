#ifndef BULLET_H
#define BULLET_H

#include "entityx/Entity.h"

struct Bullet : public entityx::Component<Bullet>
{
   Bullet();

   Bullet(double _lifeTime, long _damage);

   double lifeTime;

   double age;

   long damage;
};

#endif // BULLET_H
