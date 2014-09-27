#ifndef GUN_H
#define GUN_H

#include "entityx/Entity.h"

struct Gun : public entityx::Component<Gun>
{
   Gun();

   // Updated by player/ai control system
   bool isMainFirePressed;

   // Updated by gun system
   bool wasMainFirePressed;
};

#endif // GUN_H
