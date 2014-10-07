#include "systems/MenuSystem.h"
#include "systems/Events.h"
#include "components/Menu.h"
#include "KeyHandler.h"
#include "SDL.h"

using namespace entityx;
MenuSystem::MenuSystem(EntityManager &entities, EventManager &eventManager)
    : m_entitiyManager(entities)
    , m_eventManager(eventManager)
{
}

void MenuSystem::configure(EventManager& eventManager)
{
   eventManager.subscribe<EvKeyboard>(*this);
}

void MenuSystem::update(EntityManager& entities,
                        EventManager& events,
                        double dt)
{
}

void MenuSystem::receive(const EvKeyboard& keyboard)
{
    Menu::Handle menu;
    for (Entity entity : m_entitiyManager.entities_with_components(menu))
    {
       if(keyboard.id == SDLK_SPACE)
          menu->spMenu->onConfirm(m_eventManager);
    }
}
