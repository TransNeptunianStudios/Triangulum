#include <math.h>
#include "utils/Vector2.h"

Vector2::Vector2()
: m_x(0.0)
, m_y(0.0)
{
}

Vector2::Vector2(float x, float y)
: m_x(x)
, m_y(y)
{
}

void Vector2::normalize()
{
   m_x /= length();
   m_y /= length();
}

float Vector2::length() const
{
   return sqrt(m_x*m_x+m_y*m_y);
}
