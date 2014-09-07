#ifndef GAME_H
#define GAME_H

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

   bool update();

private:

   ActorId getNextActorId()
   { 
      return m_currentActorId++; 
   }

   void createSpaceShip();

   std::vector<Actor> m_actors;

   ActorId m_currentActorId;

   KeyHandler m_keyHandler;

   PlayerControlSystem m_playerControlSystem;

   MovementSystem m_movementSystem;

   RenderSystem m_renderSystem;
};

#endif
