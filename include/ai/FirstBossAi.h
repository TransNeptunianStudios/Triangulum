#ifndef FIRSTBOSSAI_H
#define FIRSTBOSSAI_H

#include "ai/BaseAi.h"
#include "utils/Vector2.h"

class FirstBossAi : public BaseAi
{
public:

   FirstBossAi(entityx::Entity::Id myId,
               entityx::Entity::Id enemyId,
               double scrollSpeed);

   void update(entityx::EntityManager& entities,
               double dt);

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
