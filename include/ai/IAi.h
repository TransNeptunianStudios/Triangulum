#ifndef IAI_H
#define IAI_H

#include <memory>
#include "entityx/Entity.h"

typedef uint32_t AiId;

static const AiId AI_ID_NONE           = 0;
static const AiId AI_ID_FIRST_BOSS     = 1;

class IAi
{
public:

   virtual ~IAi() {}

   virtual void setScrollSpeed(double scrollSpeed) = 0;

   virtual void update(entityx::Entity::Id myEntityId,
                       entityx::Entity::Id enemyEntityId,
                       entityx::EntityManager& entities,
                       double dt) = 0;
};

typedef std::shared_ptr<IAi> IAiSP;

#endif // IAI_H
