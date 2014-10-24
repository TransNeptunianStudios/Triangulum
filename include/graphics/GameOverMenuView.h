#ifndef GAMEOVERMENUVIEW_H
#define GAMEOVERMENUVIEW_H

#include "SFML/Graphics/Text.hpp"
#include "components/AbstractMenu.h"
#include "graphics/ScoreView.h"

class GameOverMenuView
      : public AbstractMenu
{
public:

   GameOverMenuView(int score);

   void update(entityx::EventManager& events, double dt);

   void draw(sf::RenderWindow& window);

   void onConfirm(entityx::EventManager& eventManager);

private:

   int m_score;

   sf::Text m_gameOverText;

   sf::Text m_scoreText;

   ScoreView m_scoreView;
};

#endif // GAMEOVERMENUVIEW_H
