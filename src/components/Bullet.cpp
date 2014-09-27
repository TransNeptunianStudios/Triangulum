#include "components/Bullet.h"

using namespace entityx;

Bullet::Bullet()
: ownerId(Entity::INVALID)
, lifeTime(0.0)
, age(0.0)
, damage(0)
{
}

Bullet::Bullet(Entity::Id _ownerId,
               double _lifeTime,
               long _damage)
: ownerId(_ownerId)
, lifeTime(_lifeTime)
, age(0.0)
, damage(_damage)
{
}
