#ifndef GUN_H
#define GUN_H

#include "entityx/Entity.h"
#include "SFML/System/Vector2.hpp"
#include "systems/BulletType.h"

struct Gun : public entityx::Component<Gun>
{
   Gun();

   Gun(const sf::Vector2f& _direction);

   sf::Vector2f direction;

   BulletType bulletType;

   double heat;

   double cooldownTime;

   double shootTimer;

   // Updated by player/ai control system
   bool isMainFirePressed;
};

#endif // GUN_H
