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

   void draw(const Position& pos);

   void onConfirm(entityx::EventManager& eventManager);

private:

   GLuint m_texture;

   float m_halfLogoWidth;

   float m_halfLogoHeight;

};

#endif // STARTMENUVIEW_H
