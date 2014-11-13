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
{
   m_headerText.setFont(FontRepository::getMenuFont());
   m_headerText.setCharacterSize(60);
   m_headerText.setString("Settings");

   sf::FloatRect bounds(m_headerText.getLocalBounds());
   m_headerText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_effectVolumeText.setFont(FontRepository::getMenuFont());
   m_effectVolumeText.setCharacterSize(30);
   m_effectVolumeText.setString("Effects Volume");

   bounds = m_effectVolumeText.getLocalBounds();
   m_effectVolumeText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_musicVolumeText.setFont(FontRepository::getMenuFont());
   m_musicVolumeText.setCharacterSize(30);
   m_musicVolumeText.setString("Music Volume");

   bounds = m_musicVolumeText.getLocalBounds();
   m_musicVolumeText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_fullscreenText.setFont(FontRepository::getMenuFont());
   m_fullscreenText.setCharacterSize(30);
   m_fullscreenText.setString("Enable Fullscreen");

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
    m_effectVolumeText.setPosition(ScreenSize::width()*0.5,
                                   newGameTextY);
    m_musicVolumeText.setPosition(ScreenSize::width()*0.5,
                                  newGameTextY + 50);
    m_fullscreenText.setPosition(ScreenSize::width()*0.5,
                                  newGameTextY + 100);

    window.draw(m_headerText);
    window.draw(m_effectVolumeText);
    window.draw(m_musicVolumeText);
    window.draw(m_fullscreenText);
}

void SettingsMenuView::onConfirm(entityx::EventManager& eventManager)
{
}

void SettingsMenuView::onUp(EventManager& eventManager)
{
}

void SettingsMenuView::onDown(EventManager& eventManager)
{
}

void SettingsMenuView::onCancel(EventManager &eventManager)
{
      eventManager.emit<EvShowStartMenu>(false);
}
