#include "graphics/SplashScreen.h"
#include "components/Position.h"
#include "systems/Events.h"
#include "KeyHandler.h"
#include "ScreenSize.h"

using namespace entityx;

SplashScreen::SplashScreen()
: m_texture()
, m_logoSprite()
, m_fadeIn(1000)
, m_static(3000)
, m_fadeOut(1000)
, m_timer(0)
, m_alpha(0)
{
   m_texture.loadFromFile("../images/TNS_logo.png");

   sf::Vector2u size(m_texture.getSize());
   m_logoSprite.setTexture(m_texture);
   m_logoSprite.setOrigin(size.x/2.0, size.y/2.0);
}

void SplashScreen::update(EventManager &events, double dt)
{
    m_timer += dt;

    if(m_timer < m_fadeIn)
        m_alpha = m_timer/m_fadeIn;
    else if(m_timer < m_fadeIn + m_static)
        m_alpha = 1.0f;
    else if(m_timer < m_fadeIn + m_static + m_fadeOut)
        m_alpha = 1.0f - (m_timer - m_static - m_fadeIn) / m_fadeOut;
    else
        events.emit<EvShowStartMenu>();

    // yeah, I'm a bracet rebel
}

void SplashScreen::draw(sf::RenderWindow& window)
{
   m_logoSprite.setPosition(ScreenSize::width()*0.5,
                            ScreenSize::height()*0.33);

   m_logoSprite.setColor(sf::Color(255, 255, 255, 255 * m_alpha));

   window.draw(m_logoSprite);
}

void SplashScreen::onConfirm(EventManager &eventManager)
{
    // Nothing
}

void SplashScreen::onCancel(EventManager &eventManager)
{
    // Nothing
}
