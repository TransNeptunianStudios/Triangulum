#ifndef GAMECOMPMENUVIEW_H
#define GAMECOMPMENUVIEW_H

#include "SFML/Graphics/Text.hpp"
#include "components/AbstractMenu.h"

class GameCompMenuView
      : public AbstractMenu
{
public:

   GameCompMenuView();

   void update(entityx::EventManager& events, double dt);

   void draw(sf::RenderWindow& window);

private:

   sf::Text m_text;
};

#endif // GAMECOMPMENUVIEW_H
