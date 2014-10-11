#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <map>
#include "utils/TextTexture.h"

class ScoreView
{
public:

   ScoreView(int maxScore);

   void draw(int score);

private:

   void addDigit(int digit);

   int countDigits(int number);

   typedef std::map<int, TextTexture> DigitTextureMap;

   DigitTextureMap m_digitMap;

   int m_maxScore;

   int m_maxNrOfDigits;
};

#endif // SCOREVIEW_H
