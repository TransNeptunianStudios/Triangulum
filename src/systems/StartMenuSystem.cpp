#include "systems/StartMenuSystem.h"
#include "systems/Events.h"
#include "KeyHandler.h"

using namespace entityx;
StartMenuSystem::StartMenuSystem(const KeyHandler& keyHandler)
: m_keyHandler(keyHandler)
{
}

void StartMenuSystem::update(EntityManager& entities,
                             EventManager& events,
                             double dt)
{
   if (m_keyHandler.isPressed(SDLK_SPACE))
   {
      events.emit<EvStartGame>();
   }
}
