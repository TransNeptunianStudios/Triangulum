#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "systems/PlayerControlSystem.h"
#include "systems/MovementSystem.h"
#include "systems/GunSystem.h"
#include "systems/BulletLifeTimeSystem.h"
#include "systems/AnimationSystem.h"
#include "systems/RenderSystem.h"

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Updates per milliseconds
static Uint32 MS_PER_UPDATE = 10.0;

using namespace entityx;

Game::Game()
: m_pWindow(0)
, m_GLContext(0)
, m_eventManager()
, m_entityManager(m_eventManager)
, m_systemManager(m_entityManager, m_eventManager)
, m_creator(m_entityManager)
, m_keyHandler()
{
}

void Game::init()
{
   //Initialize SDL
   if(SDL_Init(SDL_INIT_EVERYTHING|SDL_INIT_NOPARACHUTE)) // I'm a coward
   {
      std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
      std::exit(EXIT_FAILURE);
   }

   // Not needed?
   //glEnable(GL_DEPTH_TEST);

   m_pWindow = SDL_CreateWindow("Space-Shooter",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH,
                                SCREEN_HEIGHT,
                                SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

   if (m_pWindow == 0)
   {
      std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;

      SDL_Quit();

      std::exit(EXIT_FAILURE);
   }

   // Initlize OpenGl context to draw in
   m_GLContext = SDL_GL_CreateContext(m_pWindow);

   if(m_GLContext == 0)
   {
      std::cout << "OpenGl redner context could not be created: " << SDL_GetError() << std::endl;

      SDL_Quit();

      std::exit(EXIT_FAILURE);
   }

   createSystems();
   createEntities();
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
         if (event.key.keysym.sym == SDLK_ESCAPE)
         {
            exit();
         }
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
   m_systemManager.update<PlayerControlSystem>(MS_PER_UPDATE);
   m_systemManager.update<MovementSystem>(MS_PER_UPDATE);
   m_systemManager.update<GunSystem>(MS_PER_UPDATE);
   m_systemManager.update<BulletLifeTimeSystem>(MS_PER_UPDATE);
   m_systemManager.update<AnimationSystem>(MS_PER_UPDATE);
}

void Game::render()
{
    m_systemManager.update<RenderSystem>(0.0);
}

void Game::exit()
{

   //Destroy openGl context
    SDL_GL_DeleteContext(m_GLContext);

   //Destroy window
   SDL_DestroyWindow(m_pWindow);

   //Quit SDL subsystems
   SDL_Quit();

   std::exit(EXIT_SUCCESS);
}

void Game::createSystems()
{
   m_systemManager.add<PlayerControlSystem>(&m_keyHandler);
   m_systemManager.add<MovementSystem>();
   m_systemManager.add<GunSystem>(&m_keyHandler, &m_creator);
   m_systemManager.add<BulletLifeTimeSystem>();
   m_systemManager.add<AnimationSystem>();
   m_systemManager.add<RenderSystem>(m_pWindow);
   m_systemManager.configure();
}

void Game::createEntities()
{
   m_creator.createSpaceShip();
}
