#include "graphics/SettingsMenuView.h"
#include "graphics/FontRepository.h"
#include "components/Position.h"
#include "systems/Events.h"
#include "KeyHandler.h"
#include "ScreenSize.h"
#include "ResourcePath.hpp"
#include "Release.h"

using namespace entityx;

SettingsMenuView::SettingsMenuView()
: m_effectVol(70)
, m_musicVol(70)
, m_fullscreen(false)
, m_selected(EFFECTS)
{
   m_headerText.setFont(FontRepository::getMenuFont());
   m_headerText.setCharacterSize(60);
   m_headerText.setString("Settings");

   sf::FloatRect bounds(m_headerText.getLocalBounds());
   m_headerText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_effectVolumeText.setFont(FontRepository::getMenuFont());
   m_effectVolumeText.setCharacterSize(30);
   m_effectVolumeText.setString("Effects Volume" + std::string(10, ' ') 
                                + std::to_string(m_effectVol));
   bounds = m_effectVolumeText.getLocalBounds();
   m_effectVolumeText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_musicVolumeText.setString("Music Volume" + std::string(11, ' ') 
                                + std::to_string(m_musicVol));
   m_musicVolumeText.setFont(FontRepository::getMenuFont());
   m_musicVolumeText.setCharacterSize(30);
   bounds = m_musicVolumeText.getLocalBounds();
   m_musicVolumeText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_fullscreenText.setFont(FontRepository::getMenuFont());
   m_fullscreenText.setCharacterSize(30);
   m_fullscreenText.setString("Toggle Fullscreen");

   bounds = m_fullscreenText.getLocalBounds();
   m_fullscreenText.setOrigin(bounds.width/2.0, bounds.height/2.0);
}

void SettingsMenuView::update(EventManager &events, double dt)
{
}

void SettingsMenuView::draw(sf::RenderWindow& window)
{
  float newGameTextY = ScreenSize::height()*0.40;

  m_headerText.setPosition(ScreenSize::width()*0.5,
                           newGameTextY-100);
  
  m_effectVolumeText.setString("Effects Volume" +  std::string(10, ' ') 
                               +  std::to_string(m_effectVol) + "  %" );
  m_effectVolumeText.setPosition(ScreenSize::width()*0.5,
                                 newGameTextY);
  
  m_musicVolumeText.setString("Music Volume" +  std::string(11, ' ') 
                               +  std::to_string(m_musicVol)  + "  %");
  m_musicVolumeText.setPosition(ScreenSize::width()*0.5,
                                newGameTextY + 50);
  m_fullscreenText.setPosition(ScreenSize::width()*0.5,
                               newGameTextY + 100);

  switch(m_selected){
    case EFFECTS:
      m_effectVolumeText.setStyle(sf::Text::Underlined);
      m_musicVolumeText.setStyle(sf::Text::Regular);
      m_fullscreenText.setStyle(sf::Text::Regular);
      break;
    case MUSIC:
      m_effectVolumeText.setStyle(sf::Text::Regular);
      m_musicVolumeText.setStyle(sf::Text::Underlined);
      m_fullscreenText.setStyle(sf::Text::Regular);
      break;
    case FULLSCREEN:
      m_effectVolumeText.setStyle(sf::Text::Regular);
      m_musicVolumeText.setStyle(sf::Text::Regular);
      m_fullscreenText.setStyle(sf::Text::Underlined);
      break;
    }

  window.draw(m_headerText);
  window.draw(m_effectVolumeText);
  window.draw(m_musicVolumeText);
  window.draw(m_fullscreenText);
}

void SettingsMenuView::onConfirm(entityx::EventManager& eventManager)
{
  switch(m_selected){
  case EFFECTS:

     break;
  case MUSIC:

     break;
  case FULLSCREEN:
      eventManager.emit<EvToggleFullscreen>();
     break;
  }
}

void SettingsMenuView::onUp(EventManager& eventManager)
{
  if(m_selected != EFFECTS)
      eventManager.emit<EvPlaySound>(SELECT_BLIP);

  if(m_selected == MUSIC)
      m_selected = EFFECTS;
  else if(m_selected == FULLSCREEN)
      m_selected = MUSIC;
}

void SettingsMenuView::onDown(EventManager& eventManager)
{
  if(m_selected != FULLSCREEN)
      eventManager.emit<EvPlaySound>(SELECT_BLIP);

  if(m_selected == EFFECTS)
      m_selected = MUSIC;
  else if(m_selected == MUSIC)
      m_selected = FULLSCREEN;
}

void SettingsMenuView::onCancel(EventManager &eventManager)
{
    eventManager.emit<EvShowStartMenu>(false);
}

void SettingsMenuView::onLeft(EventManager &eventManager)
{
    switch(m_selected){
    case EFFECTS:
        m_effectVol = m_effectVol <= 0 ? m_effectVol : m_effectVol - 10;
       break;
    case MUSIC:
        m_musicVol = m_musicVol <= 0 ? m_musicVol : m_musicVol - 10;
        eventManager.emit<EvMusicVolume>(m_musicVol);
       break;
    case FULLSCREEN:
        eventManager.emit<EvToggleFullscreen>();
       break;
    }
}

void SettingsMenuView::onRight(EventManager &eventManager)
{
    switch(m_selected){
    case EFFECTS:
        m_effectVol = m_effectVol >= 100 ? m_effectVol : m_effectVol +10;
       break;
    case MUSIC:
        m_musicVol = m_musicVol >= 100 ? m_musicVol : m_musicVol +10;
        eventManager.emit<EvMusicVolume>(m_musicVol);
       break;
    case FULLSCREEN:
        eventManager.emit<EvToggleFullscreen>();
       break;
    }
}
