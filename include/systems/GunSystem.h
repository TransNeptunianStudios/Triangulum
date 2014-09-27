#ifndef GUNSYSTEM_H
#define GUNSYSTEM_H

#include "entityx/System.h"

class KeyHandler;

class GunSystem : public entityx::System<GunSystem>
{
public:

   GunSystem();

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);
};

#endif // GUNSYSTEM_H
