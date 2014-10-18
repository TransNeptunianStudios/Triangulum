#ifndef SHOOTATPLAYERAI_H
#define SHOOTATPLAYERAI_H

#include "ai/IAi.h"

class ShootAtPlayerAi : public IAi
{
public:

   ShootAtPlayerAi();

   void setScrollSpeed(double scrollSpeed);

   void update(entityx::Entity::Id myEntityId,
               entityx::Entity::Id enemyEntityId,
               entityx::EntityManager& entities,
               double dt);

private:

   double m_shootTimer;
};

#endif // SHOOTATPLAYERAI_H
