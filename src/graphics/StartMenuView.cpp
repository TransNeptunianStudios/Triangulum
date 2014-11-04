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

      if (m_isNewGameSelected)
      {
         m_newGameText.setStyle(sf::Text::Underlined);
         m_quitText.setStyle(sf::Text::Regular);
      }
      else
      {
         m_quitText.setStyle(sf::Text::Underlined);
         m_newGameText.setStyle(sf::Text::Regular);
      }


      window.draw(m_newGameText);

      m_quitText.setPosition(ScreenSize::width()*0.5,
                                newGameTextY + 60);

      window.draw(m_quitText);

      m_versionText.setPosition(ScreenSize::width(),
                                ScreenSize::height());
      window.draw(m_versionText);
   }
}

void StartMenuView::onConfirm(entityx::EventManager& eventManager)
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

void StartMenuView::onUp(EventManager& eventManager)
{
   if(!m_isNewGameSelected)
       eventManager.emit<EvPlaySound>(SELECT_BLIP);

   m_isNewGameSelected = true;
}

void StartMenuView::onDown(EventManager& eventManager)
{
  if(m_isNewGameSelected)
      eventManager.emit<EvPlaySound>(SELECT_BLIP);

  m_isNewGameSelected = false;
}
