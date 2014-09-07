#include "SDL.h"
#include "Game.h"
#include "components/PlayerMotionControl.h"
#include "components/Motion.h"
#include "components/Position.h"

Game::Game()
: m_actors()
, m_currentActorId(0)
, m_keyHandler()
, m_playerControlSystem()
, m_movementSystem()
{
}

void Game::init()
{
}

bool Game::update()
{
   bool quit = false;

   SDL_Event event;

   /* Poll for events */
   while (SDL_PollEvent(&event))
   {
      switch (event.type)
      {
      case SDL_KEYDOWN:
         m_keyHandler.updateKey(event.key.keysym.sym, true);
         break;
       case SDL_KEYUP:
         m_keyHandler.updateKey(event.key.keysym.sym, false);
         break;
      case SDL_QUIT:
         quit = true;
         break;
      default:
         break;
      }
   }

   m_playerControlSystem.update(m_keyHandler);
   m_movementSystem.update(0.0);

   return quit;
}

void Game::createSpaceShip()
{
   Actor spaceShip(getNextActorId());

   PlayerMotionControl* pSpaceShipMotionControl = new PlayerMotionControl();
   spaceShip.addComponent(pSpaceShipMotionControl);

   Motion* pMotion = new Motion();
   spaceShip.addComponent(pMotion);

   Position* pPosition = new Position();
   spaceShip.addComponent(pPosition);

   m_playerControlSystem.addNode(PlayerControlSystem::Node(pSpaceShipMotionControl,
                                                           pMotion));

   m_movementSystem.addNode(MovementSystem::Node(pMotion, pPosition));

   m_actors.push_back(spaceShip);
}
