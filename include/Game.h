#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"

#include "entityx/Event.h"
#include "entityx/Entity.h"
#include "entityx/System.h"

#include "GameManager.h"
#include "KeyHandler.h"
#include "AudioManager.h"

class Game
{
public:
   
   Game();

   void init();

   void run();

private:

   void createSystems();

   void processInput();

   void update();

   void render();

   void exit();

   sf::RenderWindow m_window;

   entityx::EventManager m_eventManager;

   entityx::EntityManager m_entityManager;

   entityx::SystemManager m_systemManager;

   GameManager m_gameManager;

   KeyHandler m_keyHandler;

   AudioManager m_audioManager;
};

#endif
