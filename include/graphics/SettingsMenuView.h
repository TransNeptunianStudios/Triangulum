#ifndef SETTINGSMENUVIEW_H
#define SETTINGSMENUVIEW_H

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

   void onCancel(entityx::EventManager &eventManager);
private:

   sf::Text m_headerText;

   sf::Text m_effectVolumeText;

   sf::Text m_musicVolumeText;

   sf::Text m_fullscreenText;

   enum MenuChoices{
       EFFECTS, MUSIC, FULLSCREEN
   };

   MenuChoices m_selected;
};

#endif // SETTINGSMENUVIEW_H
