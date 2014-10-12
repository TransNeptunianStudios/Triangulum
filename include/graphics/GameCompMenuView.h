#ifndef GAMECOMPMENUVIEW_H
#define GAMECOMPMENUVIEW_H

#include "components/IMenu.h"
#include "utils/TextTexture.h"

class GameCompMenuView
      : public IMenu
{
public:

   GameCompMenuView();

   void update(const KeyHandler &keyHandler,
               entityx::EventManager& eventManager);

   void draw();

   void onConfirm(entityx::EventManager& eventManager);

   void onCancel(entityx::EventManager &eventManager);

private:

   TextTexture m_textGameCompleted;
};

#endif // GAMECOMPMENUVIEW_H
