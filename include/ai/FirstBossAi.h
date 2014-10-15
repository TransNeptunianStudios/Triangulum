#ifndef FIRSTBOSSAI_H
#define FIRSTBOSSAI_H

#include "ai/IAi.h"

class FirstBossAi : public IAi
{
public:

   FirstBossAi();

   void setScrollSpeed(double scrollSpeed);

   void update(entityx::Entity::Id myEntityId,
               entityx::Entity::Id enemyEntityId,
               entityx::EntityManager& entities,
               double dt);

   void reset();

private:

   enum /* First Boss Phase */
   {
      FBP_Init,
      FBP_Attack,
   } m_fbp;

   double m_scrollSpeed;

   double m_shootTimer;
};

#endif // FIRSTBOSSAI_H
