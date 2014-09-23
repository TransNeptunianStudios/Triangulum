#ifndef ICREATABLE_H
#define ICREATABLE_H

#include "entityx/Entity.h"

class ICreatable
{
public:

   virtual ~ICreatable() {}

   virtual void create(entityx::Entity entity) = 0;
};

#endif // ICREATABLE_H
