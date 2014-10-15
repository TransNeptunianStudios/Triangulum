#include <sstream>
#include <vector>
#include <algorithm>
#include "SDL_opengl.h"
#include "graphics/ScoreView.h"
#include "graphics/FontRepository.h"

ScoreView::ScoreView(int maxScore)
: m_digitMap()
, m_maxScore(maxScore)
, m_maxNrOfDigits(countDigits(m_maxScore))
{
   for (int i = 0; i < 10; ++i)
   {
      addDigit(i);
   }
}

void ScoreView::addDigit(int digit)
{
   std::stringstream ss;
   ss << digit;

   m_digitMap[digit].setFont(FontRepository::getHudFont());
   m_digitMap[digit].setCharacterSize(30);
   m_digitMap[digit].setString(ss.str());
   m_digitMap[digit].setOrigin(m_digitMap[digit].getLocalBounds().width, 0.0);
}

int ScoreView::countDigits(int number)
{
   int count = 0;
   while (number > 0)
   {
      ++count;
      number /= 10;
   }

   return count;
}

void ScoreView::draw(int score, sf::RenderWindow& window)
{
   if (score > m_maxScore)
   {
      score = m_maxScore;
   }

   std::vector<int> digits(m_maxNrOfDigits, 0);

   std::vector<int>::iterator it = begin(digits);

   while (score > 0)
   {
      *it = score % 10;
      score /= 10;
      ++it;
   }

   //std::reverse(begin(digits), end(digits));

   float startX = 750.0f;

   for (auto i : digits)
   {
      m_digitMap[i].setPosition(startX, 525.0f);
      window.draw(m_digitMap[i]);
      startX -= 20.0;
   }
}
