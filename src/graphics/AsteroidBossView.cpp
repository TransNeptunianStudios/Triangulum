#include "graphics/AsteroidBossView.h"
#include "components/Position.h"

AsteroidBossView::AsteroidBossView(SpriteSheet* pSpriteSheet)
    : m_pSpriteSheet(pSpriteSheet)
{

}

void AsteroidBossView::draw(const Position& pos)
{
    glTranslatef(pos.position.x(),
                 pos.position.y(),
                 0.f);

     if(m_pSpriteSheet != nullptr)
         m_pSpriteSheet->draw(7, 0, 2);
}
