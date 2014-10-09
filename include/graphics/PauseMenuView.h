#ifndef PAUSEMENUVIEW_H
#define PAUSEMENUVIEW_H

#include "components/IMenu.h"

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

    GLuint m_texture;

    float m_halfLogoWidth;

    float m_halfLogoHeight;

};
#endif // PAUSEMENUVIEW_H
