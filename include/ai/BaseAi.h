#ifndef BASEAI_H
#define BASEAI_H

#include "entityx/Entity.h"
#include "ai/IAi.h"

class BaseAi : public IAi
{
public:

   BaseAi(entityx::Entity::Id myId,
          entityx::Entity::Id enemyId);

protected:

   entityx::Entity::Id getMyId() const;

   entityx::Entity::Id getEnemyId() const;

private:

   entityx::Entity::Id m_myId;

   entityx::Entity::Id m_enemyId;

};

#endif // BASEAI_H
