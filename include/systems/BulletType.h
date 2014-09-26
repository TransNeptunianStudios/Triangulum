#ifndef BULLETTYPE_H
#define BULLETTYPE_H

enum BulletType
{
   BT_Simple,
};

class BulletDamageTable
{
public:

   BulletDamageTable();

   static long lookup(BulletType type);
};

#endif // BULLETTYPE_H
