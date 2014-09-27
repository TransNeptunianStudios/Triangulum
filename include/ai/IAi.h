#ifndef IAI_H
#define IAI_H

#include <memory>
#include "entityx/Entity.h"

class Motion;
class Gun;

class IAi
{
public:

   virtual ~IAi() {}

   virtual void update(entityx::EntityManager& entities,
                       double dt) = 0;
};

typedef std::shared_ptr<IAi> IAiSP;

#endif // IAI_H
