#ifndef BASENODE_H
#define BASENODE_H

#include "ActorId.h"

class BaseNode
{
public:

   BaseNode(const ActorId& actorId);

private:

   ActorId m_actorId;
};

#endif