#include "graphics/GameCompMenuView.h"
#include "graphics/FontRepository.h"
#include "ScreenSize.h"

using namespace entityx;

GameCompMenuView::GameCompMenuView(int score)
: m_score(score)
, m_gameCompText()
, m_scoreText()
, m_scoreView(FontRepository::getMenuFont(), 30)
{
   m_gameCompText.setFont(FontRepository::getMenuFont());
   m_gameCompText.setCharacterSize(40);
   m_gameCompText.setString("Game Completed");

   m_scoreText.setFont(FontRepository::getMenuFont());
   m_scoreText.setCharacterSize(30);
   m_scoreText.setString("Score:");

   sf::FloatRect bounds(m_gameCompText.getLocalBounds());
   m_gameCompText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   bounds = m_scoreText.getLocalBounds();
   m_scoreText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_scoreView.setAlign(1);
}

void GameCompMenuView::update(EventManager &events, double dt)
{
}

void GameCompMenuView::draw(sf::RenderWindow& window)
{
   m_gameCompText.setPosition(ScreenSize::width()*0.5,
                              ScreenSize::height()*0.33);

   m_scoreText.setPosition(ScreenSize::width()*0.5,
                           ScreenSize::height()*0.5);

   m_scoreView.setPosition(ScreenSize::width()*0.5,
                           ScreenSize::height()*0.5 + 50);

   window.draw(m_gameCompText);
   window.draw(m_scoreText);
   m_scoreView.draw(m_score, window);
}
