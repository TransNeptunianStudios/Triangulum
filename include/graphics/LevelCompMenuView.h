#ifndef LEVELCOMPMENUVIEW_H
#define LEVELCOMPMENUVIEW_H

#include "components/IMenu.h"
#include "utils/Texture.h"

class LevelCompMenuView
      : public IMenu
{
public:

   LevelCompMenuView();

   void update(const KeyHandler &keyHandler,
               entityx::EventManager& eventManager);

   void draw();

   void onConfirm(entityx::EventManager& eventManager);

private:

   Texture m_texture;

   float m_halfLogoWidth;

   float m_halfLogoHeight;
};

#endif // LEVELCOMPMENUVIEW_H
