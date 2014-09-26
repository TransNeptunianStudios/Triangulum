#include "systems/BulletType.h"

BulletDamageTable::BulletDamageTable()
{
}

long BulletDamageTable::lookup(BulletType type)
{
   long bulletDamage = 0;

   switch (type) {
   case BT_Simple:
      bulletDamage = 1;
      break;
   default:
      break;
   }

   return bulletDamage;
}
