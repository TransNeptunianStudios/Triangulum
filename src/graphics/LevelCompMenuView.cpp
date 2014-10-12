#include "graphics/LevelCompMenuView.h"
#include "systems/Events.h"
#include "KeyHandler.h"

using namespace entityx;

LevelCompMenuView::LevelCompMenuView()
: m_textTexture()
{
   m_textTexture.load("Level Completed",
                      "../resources/fonts/akashi.ttf",
                      {255, 255, 255, 255},
                      30);

   m_textTexture.setTextAlignment(TA_Center);
}

void LevelCompMenuView::update(const KeyHandler &keyHandler,
                               EventManager &eventManager)
{
   if (keyHandler.isPressed(SDLK_SPACE))
   {
      eventManager.emit<EvStartGame>();
   }
}

void LevelCompMenuView::draw()
{
   m_textTexture.draw();
}

void LevelCompMenuView::onConfirm(entityx::EventManager& eventManager)
{
    eventManager.emit<EvStartGame>();
}

void LevelCompMenuView::onCancel(entityx::EventManager& eventManager)
{
    // Nothing
}
