#ifndef BULLETVIEW_H
#define BULLETVIEW_H

#include "graphics/IDrawable.h"

class BulletView : public IDrawable
{
public:

   BulletView();

   void draw(const Position& pos);
};

#endif // BULLETVIEW_H
