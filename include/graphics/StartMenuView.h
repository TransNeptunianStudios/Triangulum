#ifndef STARTMENUVIEW_H
#define STARTMENUVIEW_H

#include "SFML/Graphics/Texture.hpp"
#include "components/AbstractMenu.h"

class StartMenuView
      : public AbstractMenu
{
public:

   StartMenuView(bool withFade);

   void update(entityx::EventManager& events, double dt);

   void draw(sf::RenderWindow& window);

   void onConfirm(entityx::EventManager& eventManager);

   void onUp(entityx::EventManager &eventManager);

   void onDown(entityx::EventManager &eventManager);

private:

   sf::Texture m_texture;

   sf::Sprite m_logoSprite;

   sf::Text m_newGameText;

   sf::Text m_settingsText;

   sf::Text m_quitText;

   sf::Text m_versionText;

   double m_timer;

   double m_fadeInTimer;

   double m_showTextTimer;

   double m_alpha;

   bool m_drawText;

   enum MenuChoices{
       NEW_GAME, SETTINGS, QUIT_GAME
   };

   MenuChoices m_selected;

   bool m_isNewGameSelected;
};

#endif // STARTMENUVIEW_H
