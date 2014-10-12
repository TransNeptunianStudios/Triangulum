#ifndef LEVELCOMPMENUVIEW_H
#define LEVELCOMPMENUVIEW_H

#include "components/IMenu.h"
#include "utils/TextTexture.h"

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

   TextTexture m_textTexture;
};

#endif // LEVELCOMPMENUVIEW_H
