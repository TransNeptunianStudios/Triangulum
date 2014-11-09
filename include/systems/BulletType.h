#ifndef BULLETTYPE_H
#define BULLETTYPE_H

enum BulletType
{
   BT_Simple,
   BT_Asteroid,
};

class BulletDataTable
{
public:

   BulletDataTable();

   static long lookupDamage(BulletType type);

   static double lookupHeat(BulletType type);
};



#endif // BULLETTYPE_H
