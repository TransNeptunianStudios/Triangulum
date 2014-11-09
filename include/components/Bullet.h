#ifndef BULLET_H
#define BULLET_H

#include "entityx/Entity.h"

struct Bullet : public entityx::Component<Bullet>
{
   Bullet();

   Bullet(entityx::Entity::Id _ownerId,
          double _lifeTime,
          long _damage);

   entityx::Entity::Id ownerId;

   double lifeTime;

   double age;

   double producedHeat;

   long damage;
};

#endif // BULLET_H
