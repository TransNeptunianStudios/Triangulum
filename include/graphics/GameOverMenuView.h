#ifndef GAMEOVERMENUVIEW_H
#define GAMEOVERMENUVIEW_H

#include "SDL_opengl.h"
#include "graphics/IDrawable.h"
#include "components/IMenu.h"

class GameOverMenuView
      : public IDrawable
      , public IMenu
{
public:

   GameOverMenuView();

   void draw(const Position& pos);

   void onConfirm(entityx::EventManager& eventManager);

private:

   GLuint m_texture;

   float m_halfLogoWidth;

   float m_halfLogoHeight;

};

#endif // GAMEOVERMENUVIEW_H
