#ifndef COMPONENT_H
#define COMPONENT_H

#include "ActorId.h"

class Component
{
public:

   Component();

   void setActorId(const ActorId& actorId);

   const ActorId& getActorId() const;

private:

   ActorId m_actorId;
};

#endif