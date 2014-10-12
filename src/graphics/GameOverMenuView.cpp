#include <iostream>
#include "graphics/GameOverMenuView.h"
#include "components/Position.h"
#include "systems/Events.h"
#include "KeyHandler.h"

using namespace entityx;

GameOverMenuView::GameOverMenuView()
: m_textGameOver()
{
   m_textGameOver.load("Game Over",
                       "../resources/fonts/akashi.ttf",
                       {255, 255, 255, 255},
                       30);

   m_textGameOver.setTextAlignment(TA_Center);
}

void GameOverMenuView::update(const KeyHandler &keyHandler,
                              EventManager &eventManager)
{
   if (keyHandler.isPressed(SDLK_SPACE))
   {
      eventManager.emit<EvStartGame>();
   }
}

void GameOverMenuView::draw()
{
   m_textGameOver.draw();
}


void GameOverMenuView::onConfirm(entityx::EventManager& eventManager)
{
    eventManager.emit<EvStartGame>();
}

void GameOverMenuView::onCancel(entityx::EventManager& eventManager)
{
    // Nothing
}
