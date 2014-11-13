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
: m_texture()
, m_logoSprite()
, m_timer(0.0)
, m_fadeInTimer(2000.0)
, m_showTextTimer(4000.0)
, m_alpha(0.0)
, m_drawText(false)
, m_isNewGameSelected(true)
{   
   m_texture.loadFromFile(resourcePath() + "images/triangulum.png");

   sf::Vector2u size(m_texture.getSize());
   m_logoSprite.setTexture(m_texture);
   m_logoSprite.setOrigin(size.x/2.0, size.y/2.0);

   m_effectVolumeText.setFont(FontRepository::getMenuFont());
   m_effectVolumeText.setCharacterSize(30);
   m_effectVolumeText.setString("Effects Volume");

   sf::FloatRect bounds(m_effectVolumeText.getLocalBounds());
   m_effectVolumeText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_musicVolumeText.setFont(FontRepository::getMenuFont());
   m_musicVolumeText.setCharacterSize(30);
   m_musicVolumeText.setString("Music Volume");

   bounds = m_musicVolumeText.getLocalBounds();
   m_musicVolumeText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_versionText.setFont(FontRepository::getMenuFont());
   m_versionText.setCharacterSize(15);
   m_versionText.setString("Version " + VERSION);

   bounds = m_versionText.getLocalBounds();
   m_versionText.setOrigin(bounds.width+10, bounds.height+15);
}

void SettingsMenuView::update(EventManager &events, double dt)
{
   m_timer += dt;

   if (!m_drawText && m_fadeInTimer > m_timer)
   {
      m_alpha = m_timer/m_fadeInTimer;
   }
   else
   {
      m_alpha = 1.0;


      if (m_showTextTimer > m_timer)
      {
         m_drawText = true;
      }
   }
}

void SettingsMenuView::draw(sf::RenderWindow& window)
{
   m_logoSprite.setPosition(ScreenSize::width()*0.5,
                            ScreenSize::height()*0.33);

   m_logoSprite.setColor(sf::Color(255, 255, 255, 255 * m_alpha));

   window.draw(m_logoSprite);

   if (m_drawText)
   {
      float newGameTextY = ScreenSize::height()*0.66;

      m_effectVolumeText.setPosition(ScreenSize::width()*0.5,
                                newGameTextY);

      if (m_isNewGameSelected)
      {
         m_effectVolumeText.setStyle(sf::Text::Underlined);
         m_musicVolumeText.setStyle(sf::Text::Regular);
      }
      else
      {
         m_musicVolumeText.setStyle(sf::Text::Underlined);
         m_effectVolumeText.setStyle(sf::Text::Regular);
      }


      window.draw(m_effectVolumeText);

      m_musicVolumeText.setPosition(ScreenSize::width()*0.5,
                                newGameTextY + 60);

      window.draw(m_musicVolumeText);

      m_versionText.setPosition(ScreenSize::width(),
                                ScreenSize::height());
      window.draw(m_versionText);
   }
}

void SettingsMenuView::onConfirm(entityx::EventManager& eventManager)
{
   if (m_drawText)
   {
      if (m_isNewGameSelected)
      {
         eventManager.emit<EvStartGame>();
      }
      else
      {
         eventManager.emit<EvQuitGame>();
      }
   }
   else
   {
      m_drawText = true;
   }
}

void SettingsMenuView::onUp(EventManager& eventManager)
{
   if(!m_isNewGameSelected)
       eventManager.emit<EvPlaySound>(SELECT_BLIP);

   m_isNewGameSelected = true;
}

void SettingsMenuView::onDown(EventManager& eventManager)
{
  if(m_isNewGameSelected)
      eventManager.emit<EvPlaySound>(SELECT_BLIP);

  m_isNewGameSelected = false;
}
