#include <sstream>
#include <vector>
#include <algorithm>
#include "graphics/ScoreView.h"

ScoreView::ScoreView(const sf::Font& font, int fontSize)
: m_maxScore(1000)
, m_maxNrOfDigits(4)
, m_align(0)
, m_scoreText()
{
   m_scoreText.setFont(font);
   m_scoreText.setCharacterSize(fontSize);
   m_scoreText.setString("0");
   updateAlign();
}

void ScoreView::setAlign(int align)
{
   m_align = align;
   updateAlign();
}

void ScoreView::setPosition(float x, float y)
{
   m_scoreText.setPosition(x, y);
}

void ScoreView::draw(int score, sf::RenderWindow& window)
{
   if (score > m_maxScore)
   {
      score = m_maxScore;
   }

   std::stringstream ss;
   ss << score;

   m_scoreText.setString(ss.str());

   updateAlign();

   window.draw(m_scoreText);

}

void ScoreView::updateAlign()
{
   sf::FloatRect bounds(m_scoreText.getLocalBounds());
   m_scoreText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   if (m_align == 0)
   {
      m_scoreText.setOrigin(0.0, bounds.height/2.0);
   }
   else if (m_align == 1)
   {
      m_scoreText.setOrigin(bounds.width/2.0, bounds.height/2.0);
   }
   else if (m_align == 2)
   {
      m_scoreText.setOrigin(bounds.width, bounds.height/2.0);
   }
}
