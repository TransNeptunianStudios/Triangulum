#ifndef LEVELCOMPMENUVIEW_H
#define LEVELCOMPMENUVIEW_H

#include "SFML/Graphics/Text.hpp"
#include "components/AbstractMenu.h"

class LevelCompMenuView
      : public AbstractMenu
{
public:

   LevelCompMenuView();

   void update(entityx::EventManager& events, double dt);

   void draw(sf::RenderWindow& window);

   void onConfirm(entityx::EventManager& eventManager);

private:

   sf::Text m_text;
};

#endif // LEVELCOMPMENUVIEW_H
