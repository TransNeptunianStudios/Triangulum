#ifndef STARTMENUVIEW_H
#define STARTMENUVIEW_H

#include "SFML/Graphics/Texture.hpp"
#include "components/IMenu.h"

class StartMenuView
      : public IMenu
{
public:

   StartMenuView();

   void update(const KeyHandler &keyHandler,
               entityx::EventManager& eventManager);

   void draw(sf::RenderWindow& window);

   void onConfirm(entityx::EventManager& eventManager);

   void onCancel(entityx::EventManager &eventManager);

private:

   sf::Texture m_texture;

   sf::Sprite m_logoSprite;
};

#endif // STARTMENUVIEW_H
