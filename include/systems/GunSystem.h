#ifndef GUNSYSTEM_H
#define GUNSYSTEM_H

#include "entityx/System.h"
#include "KeyHandler.h"
#include "EntityCreator.h"

class GunSystem : public entityx::System<GunSystem>
{
public:

   GunSystem(KeyHandler* pKeyHandler,
             EntityCreator* pEntityCreator);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   KeyHandler* m_pKeyHandler;

   EntityCreator* m_pEntityCreator;
};

#endif // GUNSYSTEM_H
