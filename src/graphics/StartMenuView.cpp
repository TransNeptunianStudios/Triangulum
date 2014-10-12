#include "graphics/StartMenuView.h"
#include "components/Position.h"
#include "systems/Events.h"
#include "KeyHandler.h"

using namespace entityx;

StartMenuView::StartMenuView()
: m_texture()
{
   m_texture.load("../images/logo.png");
}

void StartMenuView::update(const KeyHandler& keyHandler,
                           EventManager& eventManager)
{
   if (keyHandler.isPressed(SDLK_SPACE))
   {
      eventManager.emit<EvStartGame>();
   }
}

void StartMenuView::draw()
{
   m_texture.draw();
}

void StartMenuView::onConfirm(entityx::EventManager& eventManager)
{
    eventManager.emit<EvStartGame>();
}

void StartMenuView::onCancel(entityx::EventManager& eventManager)
{
    //nothing
}
