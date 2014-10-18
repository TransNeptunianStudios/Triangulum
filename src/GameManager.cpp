#include "GameManager.h"
#include "EntityCreator.h"

#include "components/Menu.h"
#include "components/SpaceShip.h"

using namespace entityx;

static const int NR_OF_LEVELS = 2;

GameManager::GameManager(EntityManager& entityManager,
                         EventManager& eventManager)
: m_entityManager(entityManager)
, m_eventManager(eventManager)
, m_gameState(GS_StartMenu)
, m_currentLevel(1)
, m_currentScore(0)
{
}

void GameManager::init()
{
   m_eventManager.subscribe<EvStartGame>(*this);

   m_eventManager.subscribe<EvGameOver>(*this);

   m_eventManager.subscribe<EvBossKilled>(*this);

   m_eventManager.subscribe<EvPauseGame>(*this);

   m_eventManager.subscribe<EvResumeGame>(*this);

   m_eventManager.subscribe<EvShowStartMenu>(*this);

   SplashScreenCreator().create(m_entityManager.create());
}

GameState GameManager::getGameState() const
{
   return m_gameState;
}

void GameManager::receive(const EvStartGame& startGame)
{
   m_gameState = GS_Playing;

   m_entityManager.reset();

   m_eventManager.emit<EvInit>(m_currentLevel, m_currentScore);

   m_eventManager.emit<EvPlayMusic>();
}

void GameManager::receive(const EvGameOver& gameOver)
{
   m_gameState = GS_GameOver;

   m_entityManager.reset();

   GameOverMenuCreator().create(m_entityManager.create());
}

void GameManager::receive(const EvBossKilled& bossKilled)
{
   if (m_currentLevel == NR_OF_LEVELS)
   {
      m_gameState = GS_GameCompleted;
      m_entityManager.reset();
      GameCompMenuCreator().create(m_entityManager.create());
   }
   else
   {
      m_currentScore = 0;
      SpaceShip::Handle spaceShip;
      for (Entity entity : m_entityManager.entities_with_components(spaceShip))
      {
          m_currentScore += spaceShip->score;
      }

      ++m_currentLevel;
      m_gameState = GS_LevelCompleted;
      m_entityManager.reset();

      LevelCompMenuCreator().create(m_entityManager.create());
   }
}

void GameManager::receive(const EvPauseGame& gamePause)
{
  m_gameState = GS_Paused;
  PauseMenuCreator().create(m_entityManager.create());
}

void GameManager::receive(const EvResumeGame& gameResume)
{
    Menu::Handle menu;
    for (Entity entity : m_entityManager.entities_with_components(menu))
        m_entityManager.destroy(entity.id());

    m_gameState = GS_Playing;
}

void GameManager::receive(const EvShowStartMenu &showStartMenu)
{
   m_entityManager.reset();

   StartMenuCreator().create(m_entityManager.create());
}
