#include "ai/ShootAtPlayerAi.h"
#include "components/Position.h"
#include "components/Gun.h"
#include "components/SpaceShip.h"
#include "utils/TMath.h"

using namespace entityx;

ShootAtPlayerAi::ShootAtPlayerAi()
: m_shootTimer(0.0)
{
}

void ShootAtPlayerAi::setScrollSpeed(double scrollSpeed)
{
}

void ShootAtPlayerAi::update(Entity::Id myEntityId,
                             Entity::Id enemyEntityId,
                             EntityManager &entities,
                             double dt)
{
   auto position = entities.component<Position>(myEntityId);
   auto enemyPosition = entities.component<Position>(enemyEntityId);
   auto gun = entities.component<Gun>(myEntityId);

   if (!position.valid() ||
       !enemyPosition.valid() ||
       !gun.valid())
   {
      return;
   }

   sf::Vector2f v(enemyPosition->position.x - position->position.x,
                  enemyPosition->position.y - position->position.y);

   math::normalize(v);

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
