#ifndef IMENU_H
#define IMENU_H

#include "SFML/Graphics.hpp"
#include "entityx/Event.h"

class KeyHandler;

class AbstractMenu
{
public:

   virtual ~AbstractMenu() {}

   virtual void update(entityx::EventManager& events, double dt) = 0;

   virtual void draw(sf::RenderWindow& window) = 0;

   virtual void onConfirm(entityx::EventManager& eventManager) {};

   virtual void onCancel(entityx::EventManager& eventManager) {};

   virtual void onUp(entityx::EventManager& eventManager) {};

   virtual void onDown(entityx::EventManager& eventManager) {};
};

typedef std::shared_ptr<AbstractMenu> IMenuSP;

#endif // MENU_H
