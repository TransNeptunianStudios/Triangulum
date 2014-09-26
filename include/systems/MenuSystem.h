#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

#include "entityx/System.h"

class KeyHandler;

class MenuSystem : public entityx::System<MenuSystem>
{
public:

   MenuSystem(const KeyHandler& keyHandler);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   const KeyHandler& m_keyHandler;
};

#endif // MENUSYSTEM_H
