#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "components/PlayerMotionControl.h"
#include "components/Motion.h"
#include "components/Position.h"
#include "components/Display.h"
#include "graphics/SpaceShipView.h"

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Updates per milliseconds
static Uint32 MS_PER_UPDATE = 10.0;

Game::Game()
: m_pWindow(0)
, m_pSurface(0)
, m_actors()
, m_currentActorId(0)
, m_keyHandler()
, m_playerControlSystem()
, m_movementSystem()
, m_renderSystem()
{
}

void Game::init()
{
   //Initialize SDL
   if(SDL_Init(SDL_INIT_VIDEO ) < 0)
   {
      std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
      std::exit(EXIT_FAILURE);
   }

   m_pWindow = SDL_CreateWindow("Space-Shooter",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                SDL_WINDOW_SHOWN);

   if (m_pWindow == 0)
   {
      std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;

      SDL_Quit();

      std::exit(EXIT_FAILURE);
   }

   m_pSurface = SDL_GetWindowSurface(m_pWindow);

   createSpaceShip();
}

void Game::run()
{

   Uint32 previousTime = SDL_GetTicks();
   Uint32 lag = 0;

   // The game loop!
   while (true)
   {
      Uint32 currentTime = SDL_GetTicks();
      Uint32 delta = currentTime - previousTime;
      previousTime = currentTime;
      lag += delta;

      processInput();

      while (lag >= MS_PER_UPDATE)
      {
         update();
         lag -= MS_PER_UPDATE;
      }

      // TODO: Pass (lag / MS_PER_UPDATE) to renderer
      render();
   }
}

void Game::processInput()
{
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
         // TBR
         exit();
         break;
      default:
         break;
      }
   }
}

void Game::update()
{
   m_playerControlSystem.update(m_keyHandler);
   m_movementSystem.update(MS_PER_UPDATE);
}

void Game::render()
{
   m_renderSystem.update();

   // TBR
   //Fill the surface white
   SDL_FillRect(m_pSurface,
                NULL,
                SDL_MapRGB(m_pSurface->format, 0x00, 0x00, 0x00));

   //Update the surface
   SDL_UpdateWindowSurface(m_pWindow);
}

void Game::exit()
{
   //Destroy window
   SDL_DestroyWindow(m_pWindow);

   //Quit SDL subsystems
   SDL_Quit();

   std::exit(EXIT_SUCCESS);
}

void Game::createSpaceShip()
{
   Actor spaceShip(getNextActorId());

   // Create all components
   PlayerMotionControl* pSpaceShipMotionControl = new PlayerMotionControl();
   spaceShip.addComponent(pSpaceShipMotionControl);

   Motion* pMotion = new Motion();
   spaceShip.addComponent(pMotion);

   Position* pPosition = new Position();
   spaceShip.addComponent(pPosition);

   Display* pDisplay = new Display(new SpaceShipView());
   spaceShip.addComponent(pDisplay);

   // Register components to systems
   m_playerControlSystem.addNode(PlayerControlSystem::Node(pSpaceShipMotionControl,
                                                           pMotion));

   m_movementSystem.addNode(MovementSystem::Node(pMotion, pPosition));

   m_renderSystem.addNode(RenderSystem::Node(pPosition, pDisplay));

   m_actors.push_back(spaceShip);
}
