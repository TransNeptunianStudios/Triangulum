#ifndef LEVELCOMPMENUVIEW_H
#define LEVELCOMPMENUVIEW_H

#include "SFML/Graphics/Text.hpp"
#include "components/IMenu.h"

class LevelCompMenuView
      : public IMenu
{
public:

   LevelCompMenuView();

   void update(const KeyHandler &keyHandler,
               entityx::EventManager& eventManager);

   void draw(sf::RenderWindow& window);

   void onConfirm(entityx::EventManager& eventManager);

   void onCancel(entityx::EventManager &eventManager);

private:

   sf::Text m_text;
};

#endif // LEVELCOMPMENUVIEW_H
