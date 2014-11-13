#include "systems/RenderSystem.h"
#include "components/Position.h"
#include "components/Display.h"
#include "components/Background.h"
#include "ScreenSize.h"
#include "ResourcePath.hpp"

using namespace entityx;

RenderSystem::RenderSystem(sf::RenderWindow& window,
                           const std::shared_ptr<sf::Texture>& spSSTexture)
: m_window(window)
, m_spSSTexture(spSSTexture)
, m_bgTexture()
, m_bgSprite()
, m_sprite()
{
   m_sprite.setTexture(*m_spSSTexture);

   m_bgTexture.loadFromFile(resourcePath() + "images/bg.png");
   m_bgTexture.setRepeated(true);
   m_bgSprite.setTexture(m_bgTexture);
}

void RenderSystem::update(EntityManager &entities,
                          EventManager &events,
                          double dt)
{
   m_window.clear(sf::Color::Black);

   Background::Handle background;
   Position::Handle position;
   for (Entity entity : entities.entities_with_components(background, position))
   {
      m_bgSprite.setTextureRect(sf::IntRect(0, -position->position.y, 800, 600));
      m_window.draw(m_bgSprite);
   }

   Display::Handle display;
   for (Entity entity : entities.entities_with_components(position, display))
   {
      if (!isOutsideScreen(position->position, display->coord.width, display->coord.height))
      {
         m_sprite.setOrigin(display->coord.width/2.0,
                            display->coord.height/2.0);

         m_sprite.setPosition(position->position);

         m_sprite.setRotation(position->heading);

         m_sprite.setTextureRect(display->coord);

         m_sprite.setColor(display->color);

         m_window.draw(m_sprite);
      }
      else
      {
         entity.destroy();
      }
   }
}

bool RenderSystem::isOutsideScreen(const sf::Vector2f& position,
                                   int width,
                                   int height)
{
   return    position.x + width / 2.0 < 0.0
          || position.x - width / 2.0 > ScreenSize::width()
          || position.y - height / 2.0 > ScreenSize::height();
}
