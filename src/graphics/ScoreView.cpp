#include <sstream>
#include <vector>
#include <algorithm>
#include "SDL_opengl.h"
#include "graphics/ScoreView.h"

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

   m_digitMap[digit].load(ss.str().c_str(),
                          "../resources/fonts/munro_small.ttf",
                          { 255, 255, 255, 255},
                          30);
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

void ScoreView::draw(int score)
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

   std::reverse(begin(digits), end(digits));

   for (auto i : digits)
   {
      m_digitMap[i].draw();
      glTranslatef(20.f, 0.f, 0.f);
   }
}
