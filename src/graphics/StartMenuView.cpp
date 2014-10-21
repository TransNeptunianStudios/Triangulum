#include "graphics/StartMenuView.h"
#include "components/Position.h"
#include "systems/Events.h"
#include "KeyHandler.h"
#include "ScreenSize.h"

using namespace entityx;

StartMenuView::StartMenuView()
: m_texture()
, m_logoSprite()
, m_timer(0.0)
, m_fadeIn(2000.0)
, m_alpha(0.0)
{   
   m_texture.loadFromFile("../images/triangulum.png");

   sf::Vector2u size(m_texture.getSize());
   m_logoSprite.setTexture(m_texture);
   m_logoSprite.setOrigin(size.x/2.0, size.y/2.0);
}

void StartMenuView::update(EventManager &events, double dt)
{
   m_timer += dt;

   if (m_timer < m_fadeIn)
   {
      m_alpha = m_timer/m_fadeIn;
   }
   else
   {
      m_alpha = 1.0;
   }
}

void StartMenuView::draw(sf::RenderWindow& window)
{
   m_logoSprite.setPosition(ScreenSize::width()*0.5,
                            ScreenSize::height()*0.33);

   m_logoSprite.setColor(sf::Color(255, 255, 255, 255 * m_alpha));

   window.draw(m_logoSprite);
}

void StartMenuView::onConfirm(entityx::EventManager& eventManager)
{
    eventManager.emit<EvStartGame>();
}

void StartMenuView::onCancel(entityx::EventManager& eventManager)
{
    //nothing
}
