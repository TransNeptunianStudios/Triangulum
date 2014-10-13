#include "utils/CollisionBox.h"

CollisionBox::CollisionBox(int w, int h)
: m_w(w)
, m_h(h)
, m_offset()
, m_objectPosition()
{
}

CollisionBox::CollisionBox(int w, int h, const sf::Vector2f& offset)
: m_w(w)
, m_h(h)
, m_offset(offset)
, m_objectPosition()
{
}

void CollisionBox::setObjectPosition(const sf::Vector2f& objectPosition)
{
   m_objectPosition = objectPosition;
}

SDL_Rect CollisionBox::getRect() const
{
   SDL_Rect rect;
   rect.w = m_w;
   rect.h = m_h;
   rect.x = static_cast<int>(m_objectPosition.x+m_offset.x)-m_w/2;
   rect.y = static_cast<int>(m_objectPosition.y+m_offset.y)-m_h/2;
   return rect;
}

bool CollisionBox::checkCollision(const CollisionBox& box)
{
    SDL_Rect thisRect(getRect());

    SDL_Rect thatRect(box.getRect());

    return SDL_HasIntersection(&thisRect, &thatRect) == SDL_TRUE;
}
