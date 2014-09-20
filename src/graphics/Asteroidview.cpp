#include "graphics/Asteroidview.h"
#include "components/Position.h"

AsteroidView::AsteroidView(SpriteSheet* pSpriteSheet)
    : m_pSpriteSheet(pSpriteSheet)
{

}

void AsteroidView::draw(const Position& pos)
{
    glTranslatef(pos.position.x(),
                 pos.position.y(),
                 0.f);

     if(m_pSpriteSheet != nullptr)
         m_pSpriteSheet->draw(0, 1);
}
