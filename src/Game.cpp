#include <iostream>
#include <cstdlib>

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
#include "graphics/FontRepository.h"

// Updates per milliseconds
static sf::Int32 MS_PER_UPDATE = 10.0;

using namespace entityx;

Game::Game()
: m_window()
, m_eventManager()
, m_entityManager(m_eventManager)
, m_systemManager(m_entityManager, m_eventManager)
, m_gameManager(m_entityManager, m_eventManager)
, m_keyHandler()
, m_audioManager()
, m_inFullscreenMode(false)
{
}

void Game::init()
{
   ScreenSize::setWidth(800);
   ScreenSize::setHeight(600);

   m_window.create(sf::VideoMode(800, 600), "Triangulum");

   m_window.setVerticalSyncEnabled(true);

   FontRepository::load();

   m_gameManager.init();

   m_audioManager.init();

   createSystems();

   m_eventManager.subscribe<EvToggleFullscreen>(*this);
}

void Game::run()
{
   sf::Clock clock;
   sf::Int32 lag = 0;

   // The game loop!
   while (m_window.isOpen() && m_gameManager.isRunning())
   {
      sf::Time dt = clock.restart();

      lag += dt.asMilliseconds();

      processInput();

      while (lag > MS_PER_UPDATE)
      {
         update();
         lag -= MS_PER_UPDATE;
      }

      render(dt.asMilliseconds());
   }

   exit();
}

void Game::receive(const EvToggleFullscreen &toggleFullscreen)
{
  if(!m_inFullscreenMode){
    m_window.create( sf::VideoMode::getFullscreenModes()[0],"Triangulum", sf::Style::Fullscreen);
    m_inFullscreenMode = true;

    sf::Vector2u size = m_window.getSize();
    ScreenSize::setWidth(size.x);
    ScreenSize::setHeight(size.y);
    }
}
void Game::processInput()
{
   sf::Event event;

   while (m_window.pollEvent(event))
   {
      switch (event.type)
      {
      case sf::Event::Closed:
         m_window.close();
         exit();
         break;
      case sf::Event::KeyPressed:
         m_eventManager.emit<EvKeyboard>(event.key.code, true);
         m_keyHandler.updateKey(event.key.code, true);
         break;
       case sf::Event::KeyReleased:
         m_eventManager.emit<EvKeyboard>(event.key.code, false);
         m_keyHandler.updateKey(event.key.code, false);
         break;
      default:
         break;
      }
   }
}

void Game::update()
{
   GameState state(m_gameManager.getGameState());

   if (state == GS_Playing)
   {
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

void Game::render(double ms)
{
   m_systemManager.update<RenderSystem>(0.0);
   m_systemManager.update<HudSystem>(0.0);
   m_systemManager.update<MenuSystem>(ms);
   m_window.display();
}

void Game::exit()
{
   std::exit(EXIT_SUCCESS);
}

void Game::createSystems()
{
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
   m_systemManager.add<RenderSystem>(m_window);
   m_systemManager.add<HudSystem>(m_window);
   m_systemManager.add<MenuSystem>(m_entityManager, m_eventManager, m_window);
   m_systemManager.configure();
}
