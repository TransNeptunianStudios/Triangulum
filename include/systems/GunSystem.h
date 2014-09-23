#ifndef GUNSYSTEM_H
#define GUNSYSTEM_H

#include "entityx/System.h"

class KeyHandler;

class GunSystem : public entityx::System<GunSystem>
{
public:

   GunSystem(const KeyHandler& keyHandler);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   const KeyHandler& m_keyHandler;
};

#endif // GUNSYSTEM_H
