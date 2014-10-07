#ifndef GAMEOVERMENUVIEW_H
#define GAMEOVERMENUVIEW_H

#include "SDL_opengl.h"
#include "components/IMenu.h"

class GameOverMenuView
      : public IMenu
{
public:

   GameOverMenuView();

   void update(const KeyHandler &keyHandler,
               entityx::EventManager& eventManager);

   void draw();

private:

   GLuint m_texture;

   float m_halfLogoWidth;

   float m_halfLogoHeight;

};

#endif // GAMEOVERMENUVIEW_H
