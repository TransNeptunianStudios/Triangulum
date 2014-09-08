#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include <SDL_opengl.h>
#include "KeyHandler.h"
#include "Actor.h"
#include "systems/PlayerControlSystem.h"
#include "systems/MovementSystem.h"
#include "systems/RenderSystem.h"

class Game
{
public:
   
   Game();

   void init();

   void run();

private:

   ActorId getNextActorId()
   { 
      return m_currentActorId++; 
   }

   void processInput();

   void update();

   void render();

   void exit();

   void createSpaceShip();

   // TBR
   SDL_Window* m_pWindow;

   // TBR (from here)
   SDL_GLContext m_GLContext;

   std::vector<Actor> m_actors;

   ActorId m_currentActorId;

   KeyHandler m_keyHandler;

   PlayerControlSystem m_playerControlSystem;

   MovementSystem m_movementSystem;

   RenderSystem m_renderSystem;
};

#endif
