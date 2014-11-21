#include "ai/ShootAtPlayerWhenNearAi.h"
#include "components/Position.h"
#include "components/Gun.h"
#include "components/SpaceShip.h"
#include "components/Volume.h"
#include "components/DeathSentence.h"
#include "utils/TMath.h"

using namespace entityx;

DieWhenPlayerIsNearAI::DieWhenPlayerIsNearAI()
: m_distanceThreshold(150)
, m_timeThreshold(1000.0)
, m_timeClose(0.0)
{
}

void DieWhenPlayerIsNearAI::setScrollSpeed(double scrollSpeed)
{
}

void DieWhenPlayerIsNearAI::update(Entity::Id myEntityId,
                             Entity::Id enemyEntityId,
                             EntityManager &entities,
                             double dt)
{
   auto position = entities.component<Position>(myEntityId);
   auto volume = entities.component<Volume>(myEntityId);
   auto enemyPosition = entities.component<Position>(enemyEntityId);

   if (!position.valid() ||
       !enemyPosition.valid() ||
           entities.get(myEntityId).has_component<DeathSentence>())
   {
      return;
   }

   sf::Vector2f v(enemyPosition->position.x - position->position.x,
                  enemyPosition->position.y - position->position.y);

   if(math::magnitude(v) > m_distanceThreshold)
       m_timeClose = 0.0;
   else
       m_timeClose += dt;

   if (m_timeClose >= m_timeThreshold)
   {
       volume->m_boxes.clear();
       volume->m_boxes.push_back(CollisionBox(64, 64)); // Should check animation size
       entities.get(myEntityId).assign<DeathSentence>(400.0); // cant be longer than the animation since the volume is stil there..
   }
}
