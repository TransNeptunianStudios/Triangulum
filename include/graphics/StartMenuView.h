#ifndef STARTMENUVIEW_H
#define STARTMENUVIEW_H

#include "components/IMenu.h"
#include "utils/Texture.h"

class StartMenuView
      : public IMenu
{
public:

   StartMenuView();

   void update(const KeyHandler &keyHandler,
               entityx::EventManager& eventManager);

   void draw();

   void onConfirm(entityx::EventManager& eventManager);

   void onCancel(entityx::EventManager &eventManager);

private:

   Texture m_texture;
};

#endif // STARTMENUVIEW_H
