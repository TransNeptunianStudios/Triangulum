#include "graphics/SpaceShipView.h"
#include "components/Position.h"
#include "Animation.h"

SpaceShipView::SpaceShipView(SpriteSheet* pSpriteSheet)
: m_state(SSS_Idle)
, m_duration(0.0)
, m_pSpriteSheet(pSpriteSheet)
{
    m_test = new Animation(pSpriteSheet,
                           {{0, 0}, {1, 0}},
                           32,
                           300,
                           AS_LOOP);
    m_test->start();
}

void SpaceShipView::animate(const Vector2 velocity, double dt)
{
    m_test->update(dt);
}

void SpaceShipView::draw(const Position& pos)
{

   glTranslatef(pos.position.x(),
                pos.position.y(),
                0.f);

    if(!m_test->isFinished())
        m_test->draw();
    else
        m_pSpriteSheet->draw(0, 0);
}
