#ifndef PLAYERCONTROLSYSTEM_H
#define PLAYERCONTROLSYSTEM_H

#include "entityx/System.h"
#include "KeyHandler.h"

class PlayerControlSystem : public entityx::System<PlayerControlSystem>
{
public:

   PlayerControlSystem(KeyHandler* pKeyHandler);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   KeyHandler* m_pKeyHandler;
};

#endif
