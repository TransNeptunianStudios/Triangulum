#ifndef GAMEOVERMENUVIEW_H
#define GAMEOVERMENUVIEW_H

#include "SFML/Graphics/Text.hpp"
#include "components/AbstractMenu.h"

class GameOverMenuView
      : public AbstractMenu
{
public:

   GameOverMenuView();

   void update(entityx::EventManager& events, double dt);

   void draw(sf::RenderWindow& window);

   void onConfirm(entityx::EventManager& eventManager);

private:

   sf::Text m_text;
};

#endif // GAMEOVERMENUVIEW_H
