#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "SFML/Graphics/Texture.hpp"
#include "components/AbstractMenu.h"

class SplashScreen
      : public AbstractMenu
{
public:

   SplashScreen();

   void update(entityx::EventManager& events, double dt);

   void draw(sf::RenderWindow& window);

   void onConfirm(entityx::EventManager& eventManager);

   void onCancel(entityx::EventManager &eventManager);

private:

   sf::Texture m_texture;

   sf::Sprite m_logoSprite;

   double m_fadeIn, m_static, m_fadeOut;
   double m_timer;
   double m_alpha;
};

#endif // SPLASHSCREEN_H
