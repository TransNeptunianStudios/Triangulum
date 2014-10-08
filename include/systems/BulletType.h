#ifndef BULLETTYPE_H
#define BULLETTYPE_H

enum BulletType
{
   BT_Simple,
   BT_Asteroid,
};

class BulletDamageTable
{
public:

   BulletDamageTable();

   static long lookup(BulletType type);
};

#endif // BULLETTYPE_H
