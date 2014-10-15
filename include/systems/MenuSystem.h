#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

#include "SFML/Graphics.hpp"
#include "entityx/System.h"
#include "systems/Events.h"

class KeyHandler;

class MenuSystem
        : public entityx::System<MenuSystem>
        , public entityx::Receiver<MenuSystem>

{
public:

   MenuSystem(entityx::EntityManager &entities,
              entityx::EventManager &m_eventManager,
              sf::RenderWindow& window);

   void configure(entityx::EventManager& eventManager);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

   void receive(const EvKeyboard& keyboard);

private:

   entityx::EntityManager& m_entitiyManager;

   entityx::EventManager& m_eventManager;

   sf::RenderWindow& m_window;
};

#endif // MENUSYSTEM_H
