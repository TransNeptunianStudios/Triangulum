#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"

#include "entityx/Event.h"
#include "entityx/Entity.h"
#include "entityx/System.h"

#include "GameManager.h"
#include "KeyHandler.h"
#include "AudioManager.h"

class Game : public entityx::Receiver<Game>
{
public:

   Game();

   void init();

   void run();

   // this must be here if we dont want to pass around window?
   void receive(const EvToggleFullscreen& toggleFullscreen);

private:

   void createSystems();

   void processInput();

   void update();

   void render(double ms);

   void exit();

   sf::RenderWindow m_window;

   entityx::EventManager m_eventManager;

   entityx::EntityManager m_entityManager;

   entityx::SystemManager m_systemManager;

   GameManager m_gameManager;

   KeyHandler m_keyHandler;

   AudioManager m_audioManager;

   // there must be some way to check if we are in fullscreen
   bool m_inFullscreenMode;
};

#endif
