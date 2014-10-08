#ifndef GUN_H
#define GUN_H

#include "entityx/Entity.h"
#include "utils/Vector2.h"
#include "systems/BulletType.h"

struct Gun : public entityx::Component<Gun>
{
   Gun();

   Gun(const Vector2& _direction);

   Vector2 direction;

   BulletType bulletType;

   // Updated by player/ai control system
   bool isMainFirePressed;

   // Updated by gun system
   bool wasMainFirePressed;
};

#endif // GUN_H
