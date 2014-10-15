#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "SFML/Graphics.hpp"
#include "entityx/System.h"

class RenderSystem : public entityx::System<RenderSystem>
{
public:

   RenderSystem(sf::RenderWindow& window);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   sf::RenderWindow& m_window;

   sf::Texture m_bgTexture;

   sf::Texture m_texture;

   sf::Sprite m_bgSprite;

   sf::Sprite m_sprite;
};

#endif // RENDERSYSTEM_H
