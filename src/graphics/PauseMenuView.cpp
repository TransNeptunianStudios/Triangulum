#include "graphics/PauseMenuView.h"
#include "graphics/FontRepository.h"
#include "systems/Events.h"
#include "KeyHandler.h"
#include "ScreenSize.h"

using namespace entityx;

PauseMenuView::PauseMenuView()
: m_pauseText("Pause", FontRepository::getMenuFont(), 60)
, m_settingsText("Settings", FontRepository::getMenuFont(), 30)
, m_quitText("Quit", FontRepository::getMenuFont(), 30)
, m_selected(SETTINGS)
{
   sf::FloatRect bounds(m_pauseText.getLocalBounds());
   m_pauseText.setOrigin(bounds.width/2.0, bounds.height/2.0);
   m_pauseText.setColor(sf::Color(255, 162, 0));
   
   bounds = sf::FloatRect (m_settingsText.getLocalBounds());
      m_settingsText.setOrigin(bounds.width/2.0, bounds.height/2.0);
      
      bounds = sf::FloatRect (m_quitText.getLocalBounds());
         m_quitText.setOrigin(bounds.width/2.0, bounds.height/2.0);
}

void PauseMenuView::update(EventManager &events,
                           double dt)
{
}

void PauseMenuView::draw(sf::RenderWindow& window)
{
   m_pauseText.setPosition(ScreenSize::width()*0.5,
                      ScreenSize::height()*0.33);
   
   m_settingsText.setPosition(ScreenSize::width()*0.5,
                      ScreenSize::height()*0.66);
   
   m_quitText.setPosition(ScreenSize::width()*0.5,
                      ScreenSize::height()*0.76);

   switch(m_selected){
   case SETTINGS:
         m_settingsText.setStyle(sf::Text::Underlined);
         m_quitText.setStyle(sf::Text::Regular);
      break;
   case QUIT_GAME:
       m_settingsText.setStyle(sf::Text::Regular);
         m_quitText.setStyle(sf::Text::Underlined);
      break;
   }
   
   window.draw(m_pauseText);
   window.draw(m_settingsText);
   window.draw(m_quitText);
}


void PauseMenuView::onConfirm(entityx::EventManager& eventManager)
{
    switch(m_selected){
    case SETTINGS:
        eventManager.emit<EvShowSettingsMenu>();
        break;
    case QUIT_GAME:
        eventManager.emit<EvQuitGame>();
        break;
    }
}

void PauseMenuView::onUp(EventManager& eventManager)
{
   if(m_selected == QUIT_GAME){
       m_selected = SETTINGS;
       eventManager.emit<EvPlaySound>(SELECT_BLIP);
   }
}

void PauseMenuView::onDown(EventManager& eventManager)
{
    if(m_selected == SETTINGS){
        m_selected = QUIT_GAME;
        eventManager.emit<EvPlaySound>(SELECT_BLIP);
    }
}

void PauseMenuView::onCancel(entityx::EventManager& eventManager){
    eventManager.emit<EvResumeGame>();
}
