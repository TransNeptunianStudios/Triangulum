#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include "SDL_rect.h"
#include "utils/Vector2.h"

class CollisionBox
{
public:

   CollisionBox(int w, int h);

   CollisionBox(int w, int h, const Vector2& offset);

   void setObjectPosition(const Vector2& objectPosition);

   SDL_Rect getRect() const;

   bool checkCollision(const CollisionBox& box);

private:

   int m_w;

   int m_h;

   Vector2 m_offset;

   Vector2 m_objectPosition;
};

#endif // COLLISIONBOX_H
