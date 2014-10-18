#include "graphics/StartMenuView.h"
#include "components/Position.h"
#include "systems/Events.h"
#include "KeyHandler.h"
#include "ScreenSize.h"

using namespace entityx;

StartMenuView::StartMenuView()
: m_texture()
, m_logoSprite()
{   
   m_texture.loadFromFile("../images/logo.png");

   sf::Vector2u size(m_texture.getSize());
   m_logoSprite.setTexture(m_texture);
   m_logoSprite.setOrigin(size.x/2.0, size.y/2.0);
}

void StartMenuView::update(EventManager &events, double dt)
{
}

void StartMenuView::draw(sf::RenderWindow& window)
{
   m_logoSprite.setPosition(ScreenSize::width()*0.5,
                            ScreenSize::height()*0.33);
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
