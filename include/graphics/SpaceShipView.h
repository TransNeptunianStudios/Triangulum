#ifndef SPACESHIPVIEW_H
#define SPACESHIPVIEW_H

#include "graphics/IDrawable.h"
#include "graphics/IAnimatible.h"
#include "SpriteSheet.h"

class Animation;

enum SpaceShipState
{
   SSS_Idle,
   SSS_Right1,
   SSS_Right2,
   SSS_Right3,
};

class SpaceShipView
      : public IAnimatible
      , public IDrawable
{
public:

   SpaceShipView(SpriteSheet* pSpriteSheet);

   void animate(const Vector2 velocity, double dt);

   void draw(const Position& pos);

private:

   SpriteSheet* m_pSpriteSheet;

   SpaceShipState m_state;

   double m_duration;

   //////
   Animation *m_test;
};

#endif // SPACESHIPVIEW_H
