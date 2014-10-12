#include "graphics/GameCompMenuView.h"

using namespace entityx;

GameCompMenuView::GameCompMenuView()
: m_textGameCompleted()
{
   m_textGameCompleted.load("Game Completed",
                            "../resources/fonts/akashi.ttf",
                            {255, 255, 255, 255},
                            30);

   m_textGameCompleted.setTextAlignment(TA_Center);
}

void GameCompMenuView::update(const KeyHandler &keyHandler,
                              EventManager &eventManager)
{
}

void GameCompMenuView::draw()
{ 
   m_textGameCompleted.draw();
}


void GameCompMenuView::onConfirm(EventManager& eventManager)
{
}

void GameCompMenuView::onCancel(EventManager& eventManager)
{
}
