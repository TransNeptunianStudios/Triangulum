#include <math.h>
#include "utils/Math.h"

namespace math {

float pi()
{
   return 3.141592654f;
}

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

float angleBetween(const sf::Vector2f& v)
{
   sf::Vector2f normV(v);
   normalize(normV);
   return atan2f(normV.x, -normV.y) * (180.0/pi());
}

}
