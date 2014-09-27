#include "components/Enemy.h"

Enemy::Enemy()
: type(ET_Unknown)
{
}

Enemy::Enemy(EnemyType _type)
: type(_type)
{
}
