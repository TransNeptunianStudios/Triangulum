#include <iostream>
#include <cstdlib>

#include "SDL_ttf.h"

#include "Game.h"
#include "ScreenSize.h"
#include "systems/MenuSystem.h"
#include "systems/LevelSystem.h"
#include "systems/PlayerControlSystem.h"
#include "systems/AiControlSystem.h"
#include "systems/MovementSystem.h"
#include "systems/GunSystem.h"
#include "systems/BulletLifeTimeSystem.h"
#include "systems/DeathRowSystem.h"
#include "systems/CollisionSystem.h"
#include "systems/AnimationSystem.h"
#include "systems/AudioSystem.h"
#include "systems/RenderSystem.h"
#include "systems/HudSystem.h"
#include "systems/Events.h"

// Updates per milliseconds
static Uint32 MS_PER_UPDATE = 10.0;

using namespace entityx;

Game::Game()
: m_pWindow(0)
, m_GLContext(0)
, m_eventManager()
, m_entityManager(m_eventManager)
, m_systemManager(m_entityManager, m_eventManager)
, m_gameManager(m_entityManager, m_eventManager)
, m_keyHandler()
, m_audioManager()
{
}

void Game::init()
{
   ScreenSize::setWidth(800);
   ScreenSize::setHeight(600);

   //Initialize SDL
   if(SDL_Init(SDL_INIT_EVERYTHING|SDL_INIT_NOPARACHUTE)) // I'm a coward
   {
      std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
      std::exit(EXIT_FAILURE);
   }

   TTF_Init();

   atexit(TTF_Quit);

   // Not needed?
   //glEnable(GL_DEPTH_TEST);

   m_pWindow = SDL_CreateWindow("Space-Shooter",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                ScreenSize::width(),
                                ScreenSize::height(),
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

   initGL();

   m_gameManager.init();

   m_audioManager.init();

   createSystems();
}

void Game::initGL()
{
   //glEnable(GL_DEPTH_TEST);

   glEnable(GL_BLEND);

   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

   glClearColor(0, 0, 0, 1); // Black

   glViewport(0, 0, ScreenSize::width(), ScreenSize::height());

   glMatrixMode(GL_PROJECTION);

   glLoadIdentity();

   glOrtho(0.0, (double)ScreenSize::width(), (double)ScreenSize::height(), 0.0, -1.0, 1.0);
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
         if (event.key.keysym.sym == SDLK_q)
         {
            exit();
         }
         m_eventManager.emit<EvKeyboard>(event.key.keysym.sym, true);
         m_keyHandler.updateKey(event.key.keysym.sym, true);
         break;
       case SDL_KEYUP:
         m_eventManager.emit<EvKeyboard>(event.key.keysym.sym, false);
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
   GameState state(m_gameManager.getGameState());

   if (state == GS_StartMenu ||
       state == GS_GameOver ||
       state == GS_LevelCompleted ||
       state == GS_Paused)
   {
      m_systemManager.update<MenuSystem>(MS_PER_UPDATE);
   }
   else if (state == GS_Playing)
   {
      m_systemManager.update<MenuSystem>(MS_PER_UPDATE);
      m_systemManager.update<LevelSystem>(MS_PER_UPDATE);
      m_systemManager.update<PlayerControlSystem>(MS_PER_UPDATE);
      m_systemManager.update<AiControlSystem>(MS_PER_UPDATE);
      m_systemManager.update<MovementSystem>(MS_PER_UPDATE);
      m_systemManager.update<GunSystem>(MS_PER_UPDATE);
      m_systemManager.update<BulletLifeTimeSystem>(MS_PER_UPDATE);
      m_systemManager.update<CollisionSystem>(MS_PER_UPDATE);
      m_systemManager.update<DeathRowSystem>(MS_PER_UPDATE);
      m_systemManager.update<AnimationSystem>(MS_PER_UPDATE);
   }
}

void Game::render()
{
   m_systemManager.update<RenderSystem>(0.0);

   m_systemManager.update<HudSystem>(0.0);

   SDL_GL_SwapWindow(m_pWindow);
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
   m_systemManager.add<MenuSystem>(m_entityManager, m_eventManager);
   m_systemManager.add<LevelSystem>(m_entityManager, m_eventManager);
   m_systemManager.add<PlayerControlSystem>(m_keyHandler);
   m_systemManager.add<AiControlSystem>();
   m_systemManager.add<MovementSystem>();
   m_systemManager.add<GunSystem>();
   m_systemManager.add<BulletLifeTimeSystem>();
   m_systemManager.add<CollisionSystem>();
   m_systemManager.add<DeathRowSystem>();
   m_systemManager.add<AnimationSystem>();
   m_systemManager.add<AudioSystem>(m_audioManager);
   m_systemManager.add<RenderSystem>(new SpriteSheet("../images/SpriteSheet.png", 32));
   m_systemManager.add<HudSystem>();
   m_systemManager.configure();
}
