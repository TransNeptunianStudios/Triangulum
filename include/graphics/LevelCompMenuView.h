#ifndef LEVELCOMPMENUVIEW_H
#define LEVELCOMPMENUVIEW_H

#include "SDL_opengl.h"
#include "components/IMenu.h"

class LevelCompMenuView
      : public IMenu
{
public:

   LevelCompMenuView();

   void update(const KeyHandler &keyHandler,
               entityx::EventManager& eventManager);

   void draw();

   void onConfirm(entityx::EventManager& eventManager);

   void onCancel(entityx::EventManager &eventManager);

private:

   GLuint m_texture;

   float m_halfLogoWidth;

   float m_halfLogoHeight;
};

#endif // LEVELCOMPMENUVIEW_H
