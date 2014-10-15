#ifndef GAMECOMPMENUVIEW_H
#define GAMECOMPMENUVIEW_H

#include "SFML/Graphics/Text.hpp"
#include "components/IMenu.h"

class GameCompMenuView
      : public IMenu
{
public:

   GameCompMenuView();

   void update(const KeyHandler &keyHandler,
               entityx::EventManager& eventManager);

   void draw(sf::RenderWindow& window);

   void onConfirm(entityx::EventManager& eventManager);

   void onCancel(entityx::EventManager &eventManager);

private:

   sf::Text m_text;
};

#endif // GAMECOMPMENUVIEW_H
