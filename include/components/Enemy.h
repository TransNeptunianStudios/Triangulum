#ifndef ENEMY_H
#define ENEMY_H

#include "entityx/Entity.h"

enum EnemyType
{
   ET_Unknown,
   ET_Asteroid,
   ET_Scout,
   ET_Boss,
};

struct Enemy : public entityx::Component<Enemy>
{
   Enemy();

   Enemy(EnemyType _type);

   EnemyType type;

   int value;
};

#endif // ENEMY_H
