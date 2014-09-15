#include "graphics/SpaceShipView.h"


SpaceShipView::SpaceShipView(SpriteSheet* pSpriteSheet)
: m_state(SSS_Idle)
, m_duration(0.0)
, m_pSpriteSheet(pSpriteSheet)
{
}

void SpaceShipView::animate(const Vector2 velocity, double dt)
{
   double step = 200.0;

   switch (m_state)
   {
   case SSS_Idle:
      if (velocity.x() > 0.1)
      {
         m_state = SSS_Right1;
         m_duration = 0.0;
      }
      break;
   case SSS_Right1:
      m_duration += dt;
      if (velocity.x() > 0.1 &&
          m_duration > step)
      {
         m_state = SSS_Right2;
         m_duration = 0.0;
      }
   case SSS_Right2:
      m_duration += dt;
      if (velocity.x() > 0.1 &&
          m_duration > step)
      {
         m_state = SSS_Right3;
         m_duration = 0.0;
      }
   case SSS_Right3:
      if (velocity.x() < 0.3)
      {
         m_state = SSS_Idle;
      }
   }
}

void SpaceShipView::draw()
{
//   GLfloat color[3];
//   switch (m_state)
//   {
//   case SSS_Idle:
//      color[0] = 1.0;
//      color[1] = 1.0;
//      color[2] = 1.0;
//      break;
//   case SSS_Right1:
//      color[0] = 1.0;
//      color[1] = 0.7;
//      color[2] = 0.7;
//      break;
//   case SSS_Right2:
//      color[0] = 1.0;
//      color[1] = 0.3;
//      color[2] = 0.3;
//      break;
//   case SSS_Right3:
//      color[0] = 1.0;
//      color[1] = 0.0;
//      color[2] = 0.0;
//      break;
//   }

    if(m_pSpriteSheet != nullptr)
        m_pSpriteSheet->draw(0, 0);
}
