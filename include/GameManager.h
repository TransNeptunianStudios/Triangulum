#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "entityx/Event.h"
#include "entityx/Entity.h"
#include "systems/Events.h"

enum GameState
{
   GS_StartMenu,
   GS_Playing
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

private:

   entityx::EntityManager& m_entityManager;

   entityx::EventManager& m_eventManager;

   GameState m_gameState;

};

#endif // GAMEMANAGER_H
