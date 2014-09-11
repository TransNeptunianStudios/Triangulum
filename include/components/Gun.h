#ifndef GUN_H
#define GUN_H

#include "entityx/Entity.h"

struct Gun : public entityx::Component<Gun>
{
   Gun();

   bool isShooting;
};

#endif // GUN_H
