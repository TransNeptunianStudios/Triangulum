#ifndef SHOOTATPLAYERWHENNEARAI_H
#define SHOOTATPLAYERWHENNEARAI_H

#include "ai/IAi.h"

class ShootAtPlayerWhenNearAi : public IAi
{
public:

   ShootAtPlayerWhenNearAi();

   void setScrollSpeed(double scrollSpeed);

   void update(entityx::Entity::Id myEntityId,
               entityx::Entity::Id enemyEntityId,
               entityx::EntityManager& entities,
               double dt);

private:

   double m_shootTimer;
};

#endif // SHOOTATPLAYERWHENNEARAI_H
