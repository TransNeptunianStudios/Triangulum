#ifndef GAMECOMPMENUVIEW_H
#define GAMECOMPMENUVIEW_H

#include "SFML/Graphics/Text.hpp"
#include "components/AbstractMenu.h"
#include "graphics/ScoreView.h"

class GameCompMenuView
      : public AbstractMenu
{
public:

   GameCompMenuView(int score);

   void update(entityx::EventManager& events, double dt);

   void draw(sf::RenderWindow& window);

private:

   int m_score;

   sf::Text m_gameCompText;

   sf::Text m_scoreText;

   ScoreView m_scoreView;
};

#endif // GAMECOMPMENUVIEW_H
