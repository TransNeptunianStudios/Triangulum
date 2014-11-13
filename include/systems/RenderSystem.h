#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "SFML/Graphics.hpp"
#include "entityx/System.h"

class RenderSystem : public entityx::System<RenderSystem>
{
public:

   RenderSystem(sf::RenderWindow& window,
                const std::shared_ptr<sf::Texture>& spSSTexture);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   bool isOutsideScreen(const sf::Vector2f& position,
                        int width,
                        int height);

   sf::RenderWindow& m_window;

   std::shared_ptr<sf::Texture> m_spSSTexture;

   sf::Texture m_bgTexture;

   sf::Sprite m_bgSprite;

   sf::Sprite m_sprite;
};

#endif // RENDERSYSTEM_H
