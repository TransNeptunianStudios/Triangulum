#include "graphics/GameOverMenuView.h"
#include "graphics/FontRepository.h"
#include "systems/Events.h"
#include "KeyHandler.h"
#include "ScreenSize.h"

using namespace entityx;

GameOverMenuView::GameOverMenuView()
: m_text()
{
   m_text.setFont(FontRepository::getMenuFont());
   m_text.setCharacterSize(40);
   m_text.setString("Game Over");

   sf::FloatRect bounds(m_text.getLocalBounds());
   m_text.setOrigin(bounds.width/2.0, bounds.height/2.0);
}

void GameOverMenuView::update(const KeyHandler &keyHandler,
                              EventManager &eventManager)
{
   if (keyHandler.isPressed(sf::Keyboard::Space))
   {
      eventManager.emit<EvStartGame>();
   }
}

void GameOverMenuView::draw(sf::RenderWindow& window)
{
   m_text.setPosition(ScreenSize::width()*0.5,
                      ScreenSize::height()*0.33);

   window.draw(m_text);
}


void GameOverMenuView::onConfirm(entityx::EventManager& eventManager)
{
    eventManager.emit<EvStartGame>();
}

void GameOverMenuView::onCancel(entityx::EventManager& eventManager)
{
    // Nothing
}
