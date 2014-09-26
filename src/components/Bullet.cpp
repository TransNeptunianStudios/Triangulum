#include "components/Bullet.h"

Bullet::Bullet()
: lifeTime(0.0)
, age(0.0)
, damage(0)
{
}

Bullet::Bullet(double _lifeTime, long _damage)
: lifeTime(_lifeTime)
, age(0.0)
, damage(_damage)
{
}
