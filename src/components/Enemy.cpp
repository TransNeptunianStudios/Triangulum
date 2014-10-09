#include "components/Enemy.h"

Enemy::Enemy()
: type(ET_Unknown)
, value(0)
{
}

Enemy::Enemy(EnemyType _type)
: type(_type)
{
    switch (type) {
    case ET_Asteroid:
        value = 5;
        break;
    case ET_Boss:
        value = 20;
        break;
    default:
        value = 0;
        break;
    }
}
