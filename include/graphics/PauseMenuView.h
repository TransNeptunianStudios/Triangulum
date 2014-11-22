#ifndef PAUSEMENUVIEW_H
#define PAUSEMENUVIEW_H

#include "SFML/Graphics/Text.hpp"
#include "components/AbstractMenu.h"

class PauseMenuView
      : public AbstractMenu
{
public:

    PauseMenuView();

    void update(entityx::EventManager& events, double dt);

    void draw(sf::RenderWindow& window);
    
    void onConfirm(entityx::EventManager& eventManager);
 
    void onUp(entityx::EventManager &eventManager);
 
    void onDown(entityx::EventManager &eventManager);

    void onCancel(entityx::EventManager &eventManager);

 private:

    sf::Text m_pauseText;
    
    sf::Text m_settingsText;
    sf::Text m_quitText;
    
    enum MenuChoices{
        SETTINGS, QUIT_GAME
    };
 
    MenuChoices m_selected;
};

#endif // PAUSEMENUVIEW_H
