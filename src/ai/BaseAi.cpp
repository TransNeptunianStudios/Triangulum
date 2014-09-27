#include "ai/BaseAi.h"

using namespace entityx;

BaseAi::BaseAi(Entity::Id myId,
               Entity::Id enemyId)
: m_myId(myId)
, m_enemyId(enemyId)
{
}

Entity::Id BaseAi::getMyId() const
{
   return m_myId;
}

Entity::Id BaseAi::getEnemyId() const
{
   return m_enemyId;
}
