#ifndef LEVELCOMPMENUVIEW_H
#define LEVELCOMPMENUVIEW_H

#include "SDL_opengl.h"
#include "graphics/IDrawable.h"
#include "components/IMenu.h"

class LevelCompMenuView
      : public IDrawable
      , public IMenu
{
public:

   LevelCompMenuView();

   void update(const KeyHandler &keyHandler,
               entityx::EventManager& eventManager);

   void draw(const Position& pos);

private:

   GLuint m_texture;

   float m_halfLogoWidth;

   float m_halfLogoHeight;
};

#endif // LEVELCOMPMENUVIEW_H
