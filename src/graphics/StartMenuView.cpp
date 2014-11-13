#include "graphics/StartMenuView.h"
#include "graphics/FontRepository.h"
#include "components/Position.h"
#include "systems/Events.h"
#include "KeyHandler.h"
#include "ScreenSize.h"
#include "ResourcePath.hpp"
#include "Release.h"

using namespace entityx;

StartMenuView::StartMenuView()
: m_texture()
, m_logoSprite()
, m_timer(0.0)
, m_fadeInTimer(2000.0)
, m_showTextTimer(4000.0)
, m_alpha(0.0)
, m_drawText(false)
, m_isNewGameSelected(true)
, m_selected(NEW_GAME)
{   
   m_texture.loadFromFile(resourcePath() + "images/triangulum.png");

   sf::Vector2u size(m_texture.getSize());
   m_logoSprite.setTexture(m_texture);
   m_logoSprite.setOrigin(size.x/2.0, size.y/2.0);

   m_newGameText.setFont(FontRepository::getMenuFont());
   m_newGameText.setCharacterSize(30);
   m_newGameText.setString("New Game");

   sf::FloatRect bounds(m_newGameText.getLocalBounds());
   m_newGameText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_settingsText.setFont(FontRepository::getMenuFont());
   m_settingsText.setCharacterSize(30);
   m_settingsText.setString("Settings");

   bounds = m_settingsText.getLocalBounds();
   m_settingsText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_quitText.setFont(FontRepository::getMenuFont());
   m_quitText.setCharacterSize(30);
   m_quitText.setString("Quit");

   bounds = m_quitText.getLocalBounds();
   m_quitText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_versionText.setFont(FontRepository::getMenuFont());
   m_versionText.setCharacterSize(15);
   m_versionText.setString("Version " + VERSION);

   bounds = m_versionText.getLocalBounds();
   m_versionText.setOrigin(bounds.width+10, bounds.height+15);
}

void StartMenuView::update(EventManager &events, double dt)
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

void StartMenuView::draw(sf::RenderWindow& window)
{
   m_logoSprite.setPosition(ScreenSize::width()*0.5,
                            ScreenSize::height()*0.33);

   m_logoSprite.setColor(sf::Color(255, 255, 255, 255 * m_alpha));

   window.draw(m_logoSprite);

   if (m_drawText)
   {
      float newGameTextY = ScreenSize::height()*0.66;

      m_newGameText.setPosition(ScreenSize::width()*0.5,
                                newGameTextY);

      m_settingsText.setPosition(ScreenSize::width()*0.5,
                                newGameTextY+50);

      m_quitText.setPosition(ScreenSize::width()*0.5,
                                newGameTextY + 100);

      m_versionText.setPosition(ScreenSize::width(),
                                ScreenSize::height());

      switch(m_selected){
      case NEW_GAME:
            m_newGameText.setStyle(sf::Text::Underlined);
            m_settingsText.setStyle(sf::Text::Regular);
            m_quitText.setStyle(sf::Text::Regular);
         break;
      case SETTINGS:
            m_quitText.setStyle(sf::Text::Regular);
            m_settingsText.setStyle(sf::Text::Underlined);
            m_newGameText.setStyle(sf::Text::Regular);
         break;
      case QUIT_GAME:
            m_quitText.setStyle(sf::Text::Underlined);
            m_settingsText.setStyle(sf::Text::Regular);
            m_newGameText.setStyle(sf::Text::Regular);
         break;
      }
      window.draw(m_newGameText);
      window.draw(m_settingsText);
      window.draw(m_quitText);
      window.draw(m_versionText);
   }
}

void StartMenuView::onConfirm(entityx::EventManager& eventManager)
{
   if (m_drawText)
   {
      switch(m_selected){
      case NEW_GAME:
         eventManager.emit<EvStartGame>();
         break;
      case SETTINGS:
         eventManager.emit<EvShowSettings>();
         break;
      case QUIT_GAME:
         eventManager.emit<EvQuitGame>();
         break;
      }
   }
   else
   {
      m_drawText = true;
   }
}

void StartMenuView::onUp(EventManager& eventManager)
{
   if(m_selected != NEW_GAME)
       eventManager.emit<EvPlaySound>(SELECT_BLIP);

   if(m_selected == QUIT_GAME)
       m_selected = SETTINGS;
   else if(m_selected == SETTINGS)
       m_selected = NEW_GAME;
}

void StartMenuView::onDown(EventManager& eventManager)
{
   if(m_selected != QUIT_GAME)
       eventManager.emit<EvPlaySound>(SELECT_BLIP);

   if(m_selected == NEW_GAME)
       m_selected = SETTINGS;
   else if(m_selected == SETTINGS)
       m_selected = QUIT_GAME;
}
