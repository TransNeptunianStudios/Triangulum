#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <map>
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Text.hpp"

class ScoreView
{
public:

   ScoreView(int maxScore);

   void draw(int score, sf::RenderWindow& window);

private:

   void addDigit(int digit);

   int countDigits(int number);

   typedef std::map<int, sf::Text> DigitTextureMap;

   DigitTextureMap m_digitMap;

   int m_maxScore;

   int m_maxNrOfDigits;
};

#endif // SCOREVIEW_H
