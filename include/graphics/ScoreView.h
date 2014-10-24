#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <map>
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"

class ScoreView
{
public:

   ScoreView(const sf::Font& font, int fontSize);

   // 0 = right, 1 = center, 2 = left
   void setAlign(int align);

   void setPosition(float x, float y);

   void draw(int score, sf::RenderWindow& window);

private:

   void updateAlign();

   const int m_maxScore;

   const int m_maxNrOfDigits;

   int m_align;

   sf::Text m_scoreText;
};

#endif // SCOREVIEW_H
