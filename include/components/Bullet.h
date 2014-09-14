#ifndef BULLET_H
#define BULLET_H

#include "entityx/Entity.h"

struct Bullet : public entityx::Component<Bullet>
{
   Bullet();

   Bullet(double _lifeTime);

   double lifeTime;

   double age;
};

#endif // BULLET_H
