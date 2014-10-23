#ifndef PAUSEMENUVIEW_H
#define PAUSEMENUVIEW_H

#include "SFML/Graphics/Text.hpp"
#include "components/AbstractMenu.h"

class PauseMenuView
      : public AbstractMenu
{
public:

    PauseMenuView();

    void update(entityx::EventManager& events, double dt);

    void draw(sf::RenderWindow& window);

    void onCancel(entityx::EventManager &eventManager);

 private:

    sf::Text m_text;
};

#endif // PAUSEMENUVIEW_H
