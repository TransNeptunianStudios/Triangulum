#ifndef STARTMENUVIEW_H
#define STARTMENUVIEW_H

#include "graphics/IDrawable.h"

class StartMenuView : public IDrawable
{
public:

   StartMenuView();

   void draw(const Position& pos);
};

#endif // STARTMENUVIEW_H
