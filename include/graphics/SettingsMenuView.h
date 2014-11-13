#ifndef SETTINGSMENUVIEW_H
#define SETTINGSMENUVIEW_H

#include "SFML/Graphics/Texture.hpp"
#include "components/AbstractMenu.h"

class SettingsMenuView
      : public AbstractMenu
{
public:

   SettingsMenuView();

   void update(entityx::EventManager& events, double dt);

   void draw(sf::RenderWindow& window);

   void onConfirm(entityx::EventManager& eventManager);

   void onUp(entityx::EventManager &eventManager);

   void onDown(entityx::EventManager &eventManager);

private:

   sf::Texture m_texture;

   sf::Sprite m_logoSprite;

   sf::Text m_effectVolumeText;

   sf::Text m_musicVolumeText;

   sf::Text m_versionText;

   double m_timer;

   double m_fadeInTimer;

   double m_showTextTimer;

   double m_alpha;

   bool m_drawText;

   bool m_isNewGameSelected;
};

#endif // SETTINGSMENUVIEW_H
