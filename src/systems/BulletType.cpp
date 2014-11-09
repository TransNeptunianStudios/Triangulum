#include "systems/BulletType.h"

BulletDataTable::BulletDataTable()
{
}

long BulletDataTable::lookupDamage(BulletType type)
{
   long bulletDamage = 0;

   switch (type)
   {
   case BT_Simple:
   case BT_Asteroid:
      bulletDamage = 1;
      break;
   default:
      break;
   }

   return bulletDamage;
}


double BulletDataTable::lookupHeat(BulletType type)
{
   double heat = 0.0;

   switch (type)
   {
   case BT_Simple:
   case BT_Asteroid:
      heat = 4.0;
      break;
   default:
      break;
   }

   return heat;
}
