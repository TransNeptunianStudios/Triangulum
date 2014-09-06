
#include "Actor.h"

Actor::Actor(const ActorId& id)
: m_id(id)
, m_components()
{
}

void Actor::addComponent(Component* pComponent)
{
   m_components.push_back(pComponent);
}