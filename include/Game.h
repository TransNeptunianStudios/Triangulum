#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_opengl.h"

#include "entityx/Event.h"
#include "entityx/Entity.h"
#include "entityx/System.h"

#include "EntityCreator.h"
#include "KeyHandler.h"

class Game
{
public:
   
   Game();

   void init();

   void run();

private:

   void processInput();

   void update();

   void render();

   void exit();

   void createSystems();

   void createEntities();

   void createSpaceShip();

   // TBR
   SDL_Window* m_pWindow;

   // TBR (from here)
   SDL_GLContext m_GLContext;

   entityx::EventManager m_eventManager;

   entityx::EntityManager m_entityManager;

   entityx::SystemManager m_systemManager;

   EntityCreator m_creator;

   KeyHandler m_keyHandler;
};

#endif
