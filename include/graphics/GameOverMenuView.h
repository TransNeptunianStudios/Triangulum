#ifndef GAMEOVERMENUVIEW_H
#define GAMEOVERMENUVIEW_H

#include "components/IMenu.h"
#include "utils/TextTexture.h"

class GameOverMenuView
      : public IMenu
{
public:

   GameOverMenuView();

   void update(const KeyHandler &keyHandler,
               entityx::EventManager& eventManager);

   void draw();

   void onConfirm(entityx::EventManager& eventManager);

   void onCancel(entityx::EventManager &eventManager);

private:

   TextTexture m_textGameOver;
};

#endif // GAMEOVERMENUVIEW_H
