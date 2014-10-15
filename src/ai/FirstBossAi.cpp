#include "ai/FirstBossAi.h"
#include "components/Motion.h"
#include "components/Position.h"
#include "components/Gun.h"
#include "components/SpaceShip.h"
#include <math.h>

using namespace entityx;

FirstBossAi::FirstBossAi()
: m_scrollSpeed(0.0)
, m_fbp(FBP_Init)
, m_shootTimer(-1.0)
{
}

void FirstBossAi::setScrollSpeed(double scrollSpeed)
{
   m_scrollSpeed = scrollSpeed;
}

void FirstBossAi::update(entityx::Entity::Id myEntityId,
                         entityx::Entity::Id enemyEntityId,
                         entityx::EntityManager& entities,
                         double dt)
{
   auto motion = entities.component<Motion>(myEntityId);
   auto position = entities.component<Position>(myEntityId);
   auto gun = entities.component<Gun>(myEntityId);

   if (!motion.valid() ||
       !position.valid() ||
       !gun.valid())
   {
      return;
   }

   switch (m_fbp)
   {
   case FBP_Init:
      if (position->position.y >= 100.0)
      {
         motion->velocity.y = 0.0;
         m_fbp = FBP_Attack;
      }
      else
      {
         motion->velocity.y = m_scrollSpeed;
      }
      break;
   case FBP_Attack:
   {
      auto enemyPosition = entities.component<Position>(enemyEntityId);
      double horSpeed = 50.0;

      if (position->position.x < enemyPosition->position.x)
      {
         motion->velocity.x = horSpeed;
      }
      else if (position->position.x > enemyPosition->position.x)
      {
         motion->velocity.x = -horSpeed;
      }
      else
      {
         motion->velocity.x = 0.0;
      }

      sf::Vector2f v(enemyPosition->position.x - position->position.x,
                     enemyPosition->position.y - position->position.y);

      float length = sqrt(v.x*v.x + v.y*v.y);
      v.x /= length;
      v.y /= length;

      gun->direction = v;

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

void FirstBossAi::reset()
{
   m_scrollSpeed = 0.0;
   m_fbp = FBP_Init;
   m_shootTimer = -1.0;
}
