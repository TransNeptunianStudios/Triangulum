#ifndef IMENU_H
#define IMENU_H

#include "SFML/Graphics.hpp"
#include "entityx/Event.h"

class KeyHandler;

class IMenu
{
public:

   virtual ~IMenu() {}

   virtual void update(entityx::EventManager& events, double dt) = 0;

   virtual void draw(sf::RenderWindow& window) = 0;

   virtual void onConfirm(entityx::EventManager& eventManager) = 0;

   virtual void onCancel(entityx::EventManager& eventManager) = 0;
};

typedef std::shared_ptr<IMenu> IMenuSP;

#endif // IMENU_H
