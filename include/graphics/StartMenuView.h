#ifndef STARTMENUVIEW_H
#define STARTMENUVIEW_H

#include "graphics/IDrawable.h"
#include "components/IMenu.h"

class StartMenuView
      : public IDrawable
      , public IMenu
{
public:

   StartMenuView();

   void update(const KeyHandler &keyHandler,
               entityx::EventManager& eventManager);

   void draw(const Position& pos);
};

#endif // STARTMENUVIEW_H
