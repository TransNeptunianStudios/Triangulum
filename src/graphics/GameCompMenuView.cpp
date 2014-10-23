#include "graphics/GameCompMenuView.h"
#include "graphics/FontRepository.h"
#include "ScreenSize.h"

using namespace entityx;

GameCompMenuView::GameCompMenuView()
: m_text()
{
   m_text.setFont(FontRepository::getMenuFont());
   m_text.setCharacterSize(40);
   m_text.setString("Game Completed");

   sf::FloatRect bounds(m_text.getLocalBounds());
   m_text.setOrigin(bounds.width/2.0, bounds.height/2.0);
}

void GameCompMenuView::update(EventManager &events, double dt)
{
}

void GameCompMenuView::draw(sf::RenderWindow& window)
{ 
   m_text.setPosition(ScreenSize::width()*0.5,
                      ScreenSize::height()*0.33);

   window.draw(m_text);
}
