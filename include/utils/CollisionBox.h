#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include "SDL_rect.h"
#include "SFML/System/Vector2.hpp"

class CollisionBox
{
public:

   CollisionBox(int w, int h);

   CollisionBox(int w, int h, const sf::Vector2f& offset);

   void setObjectPosition(const sf::Vector2f& objectPosition);

   SDL_Rect getRect() const;

   bool checkCollision(const CollisionBox& box);

private:

   int m_w;

   int m_h;

   sf::Vector2f m_offset;

   sf::Vector2f m_objectPosition;
};

#endif // COLLISIONBOX_H
