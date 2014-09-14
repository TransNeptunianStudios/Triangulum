#ifndef BULLETLIFETIMESYSTEM_H
#define BULLETLIFETIMESYSTEM_H

#include "entityx/System.h"

class BulletLifeTimeSystem : public entityx::System<BulletLifeTimeSystem>
{
public:

   BulletLifeTimeSystem();

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);
};

#endif // BULLETLIFETIMESYSTEM_H
