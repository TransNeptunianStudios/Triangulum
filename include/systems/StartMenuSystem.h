#ifndef STARTMENUSYSTEM_H
#define STARTMENUSYSTEM_H

#include "entityx/System.h"

class KeyHandler;

class StartMenuSystem : public entityx::System<StartMenuSystem>
{
public:

   StartMenuSystem(const KeyHandler& keyHandler);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   const KeyHandler& m_keyHandler;
};

#endif // STARTMENUSYSTEM_H
