#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "entityx/Event.h"
#include "entityx/Entity.h"
#include "systems/Events.h"

enum GameState
{
   GS_StartMenu,
   GS_Playing,
   GS_Paused,
   GS_GameOver,
   GS_LevelCompleted,
};

class GameManager : public entityx::Receiver<GameManager>
{
public:

   GameManager(entityx::EntityManager& entityManager,
               entityx::EventManager& eventManager);

   void init();

   GameState getGameState() const;

   void receive(const EvStartGame& startGame);

   void receive(const EvGameOver& gameOver);

   void receive(const EvBossKilled& bossKilled);

   void receive(const EvPauseGame& gamePause);

   void receive(const EvResumeGame& gameResume);

private:

   entityx::EntityManager& m_entityManager;

   entityx::EventManager& m_eventManager;

   GameState m_gameState;

   int m_currentLevel;
};

#endif // GAMEMANAGER_H
