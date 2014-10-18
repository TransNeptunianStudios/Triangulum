#include <math.h>
#include "utils/Math.h"

namespace math {

float magnitude(const sf::Vector2f &v)
{
   return sqrt(v.x*v.x + v.y*v.y);
}

void normalize(sf::Vector2f& v)
{
   float mag = magnitude(v);

   if (mag > 0.0f)
   {
      v.x /= mag;
      v.y /= mag;
   }
}

float dotProduct(const sf::Vector2f& v1,
                 const sf::Vector2f& v2)
{
   return v1.x*v2.x + v1.y*v2.y;
}

float angleBetween(const sf::Vector2f& v1,
                   const sf::Vector2f& v2)
{
   sf::Vector2f normV1(v1);
   sf::Vector2f normV2(v2);
   normalize(normV1);
   normalize(normV2);
   return acos(dotProduct(normV1, normV2)) * (180.0/M_PI);
}



}
