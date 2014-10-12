#ifndef PAUSEMENUVIEW_H
#define PAUSEMENUVIEW_H

#include "components/IMenu.h"
#include "utils/TextTexture.h"

class PauseMenuView
      : public IMenu
{
public:

    PauseMenuView();

    void update(const KeyHandler &keyHandler,
                entityx::EventManager& eventManager);

    void draw();

    void onConfirm(entityx::EventManager& eventManager);

    void onCancel(entityx::EventManager &eventManager);

 private:

    TextTexture m_textPause;
};

#endif // PAUSEMENUVIEW_H
