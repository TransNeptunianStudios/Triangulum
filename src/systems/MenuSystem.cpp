#include "systems/MenuSystem.h"
#include "systems/Events.h"
#include "components/Menu.h"
#include "KeyHandler.h"

using namespace entityx;
MenuSystem::MenuSystem(const KeyHandler& keyHandler)
: m_keyHandler(keyHandler)
{
}

void MenuSystem::update(EntityManager& entities,
                        EventManager& events,
                        double dt)
{
   Menu::Handle menu;
   for (Entity entity : entities.entities_with_components(menu))
   {
      menu->spMenu->update(m_keyHandler, events);
   }
}
