#include "graphics/GameOverMenuView.h"
#include "graphics/FontRepository.h"
#include "systems/Events.h"
#include "KeyHandler.h"
#include "ScreenSize.h"

using namespace entityx;

GameOverMenuView::GameOverMenuView(int score)
: m_score(score)
, m_gameOverText()
, m_scoreText()
, m_scoreView(FontRepository::getMenuFont(), 30)
{
   m_gameOverText.setFont(FontRepository::getMenuFont());
   m_gameOverText.setCharacterSize(40);
   m_gameOverText.setString("Game Over");

   m_scoreText.setFont(FontRepository::getMenuFont());
   m_scoreText.setCharacterSize(30);
   m_scoreText.setString("Score:");

   sf::FloatRect bounds(m_gameOverText.getLocalBounds());
   m_gameOverText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   bounds = m_scoreText.getLocalBounds();
   m_scoreText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_scoreView.setAlign(1);
}

void GameOverMenuView::update(EventManager &events, double dt)
{
}

void GameOverMenuView::draw(sf::RenderWindow& window)
{
   m_gameOverText.setPosition(ScreenSize::width()*0.5,
                              ScreenSize::height()*0.33);

   m_scoreText.setPosition(ScreenSize::width()*0.5,
                           ScreenSize::height()*0.5);

   m_scoreView.setPosition(ScreenSize::width()*0.5,
                           ScreenSize::height()*0.5 + 50);

   window.draw(m_gameOverText);
   window.draw(m_scoreText);
   m_scoreView.draw(m_score, window);
}


void GameOverMenuView::onConfirm(entityx::EventManager& eventManager)
{
    eventManager.emit<EvStartGame>();
}
