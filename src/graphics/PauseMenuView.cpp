#include "graphics/PauseMenuView.h"
#include "systems/Events.h"
#include "KeyHandler.h"

PauseMenuView::PauseMenuView()
: m_textPause()
{
   m_textPause.load("Pause",
                    "../resources/fonts/akashi.ttf",
                    {255, 255, 255, 255},
                    30);

   m_textPause.setTextAlignment(TA_Center);
}

void PauseMenuView::update(const KeyHandler &keyHandler, entityx::EventManager &eventManager)
{
    if (keyHandler.isPressed(SDLK_ESCAPE))
    {
       eventManager.emit<EvResumeGame>();
    }
}

void PauseMenuView::draw()
{
   m_textPause.draw();
}

void PauseMenuView::onConfirm(entityx::EventManager& eventManager)
{
    //Nothing
}


void PauseMenuView::onCancel(entityx::EventManager& eventManager){
    eventManager.emit<EvResumeGame>();
}
