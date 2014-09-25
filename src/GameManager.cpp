#include "GameManager.h"
#include "EntityCreator.h"

using namespace entityx;

GameManager::GameManager(EntityManager& entityManager,
                         EventManager& eventManager)
: m_entityManager(entityManager)
, m_eventManager(eventManager)
, m_gameState(GS_StartMenu)
{
}

void GameManager::init()
{
   m_eventManager.subscribe<EvStartGame>(*this);

   m_eventManager.subscribe<EvGameOver>(*this);

   StartMenuCreator().create(m_entityManager.create());
}

GameState GameManager::getGameState() const
{
   return m_gameState;
}

void GameManager::receive(const EvStartGame& startGame)
{
   m_gameState = GS_Playing;

   m_entityManager.reset();

   m_eventManager.emit<EvInit>();
}

void GameManager::receive(const EvGameOver &gameOver)
{
   m_gameState = GS_StartMenu;

   m_entityManager.reset();

   StartMenuCreator().create(m_entityManager.create());
}
