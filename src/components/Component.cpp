#include "components/Component.h"

Component::Component()
{
}

void Component::setActorId(const ActorId& actorId)
{
   m_actorId = actorId;
}

const ActorId& Component::getActorId() const
{
   return m_actorId;
}