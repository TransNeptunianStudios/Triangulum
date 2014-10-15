#ifndef PAUSEMENUVIEW_H
#define PAUSEMENUVIEW_H

#include "SFML/Graphics/Text.hpp"
#include "components/IMenu.h"

class PauseMenuView
      : public IMenu
{
public:

    PauseMenuView();

    void update(const KeyHandler &keyHandler,
                entityx::EventManager& eventManager);

    void draw(sf::RenderWindow& window);

    void onConfirm(entityx::EventManager& eventManager);

    void onCancel(entityx::EventManager &eventManager);

 private:

    sf::Text m_text;
};

#endif // PAUSEMENUVIEW_H
