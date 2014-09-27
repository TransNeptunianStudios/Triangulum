#include "ai/FirstBossAi.h"
#include "components/Motion.h"
#include "components/Position.h"
#include "components/Gun.h"
#include "components/SpaceShip.h"

using namespace entityx;

FirstBossAi::FirstBossAi(entityx::Entity::Id myId,
                         entityx::Entity::Id enemyId,
                         double scrollSpeed)
: BaseAi(myId, enemyId)
, m_scrollSpeed(scrollSpeed)
, m_fbp(FBP_Init)
, m_shootTimer(-1.0)
{
}

void FirstBossAi::update(EntityManager& entities,
                         double dt)
{
   auto motion = entities.component<Motion>(getMyId());
   auto position = entities.component<Position>(getMyId());
   auto gun = entities.component<Gun>(getMyId());

   if (!motion.valid() ||
       !position.valid() ||
       !gun.valid())
   {
      return;
   }

   switch (m_fbp)
   {
   case FBP_Init:
      if (position->position.y() >= 100.0)
      {
         motion->velocity.y() = 0.0;
         m_fbp = FBP_Attack;
      }
      else
      {
         motion->velocity.y() = m_scrollSpeed;
      }
      break;
   case FBP_Attack:
   {
      auto enemyPosition = entities.component<Position>(getEnemyId());
      double horSpeed = 50.0;

      if (position->position.x() < enemyPosition->position.x())
      {
         motion->velocity.x() = horSpeed;
      }
      else if (position->position.x() > enemyPosition->position.x())
      {
         motion->velocity.x() = -horSpeed;
      }
      else
      {
         motion->velocity.x() = 0.0;
      }

      if (gun->isMainFirePressed)
      {
         gun->isMainFirePressed = false;
         m_shootTimer = 2000.0;
      }
      else if (m_shootTimer <= 0.0)
      {
         gun->isMainFirePressed = true;
      }
      else
      {
         m_shootTimer -= dt;
      }
   }
      break;
   default:
      break;
   }
}
