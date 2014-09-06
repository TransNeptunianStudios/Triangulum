#ifndef ACTOR_H
#define ACTOR_H

#include <vector>
#include "ActorId.h"

class Component;

class Actor
{
public:

   Actor(const ActorId& id);

   void addComponent(Component* pCompoent);

private:

   ActorId m_id;

   std::vector<Component*> m_components; 
};

#endif