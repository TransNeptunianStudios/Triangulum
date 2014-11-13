#ifndef HUDSYSTEM_H
#define HUDSYSTEM_H

#include "SFML/Graphics/Text.hpp"
#include "entityx/System.h"
#include "entityx/Event.h"
#include "graphics/ScoreView.h"

class HudSystem
      : public entityx::System<HudSystem>
{
public:

   HudSystem(sf::RenderWindow& window,
             const std::shared_ptr<sf::Texture> &spSSTexture);

   void update(entityx::EntityManager& entities,
               entityx::EventManager& events,
               double dt);

private:

   sf::RenderWindow& m_window;

   std::shared_ptr<sf::Texture> m_spSSTexture;

   sf::Text m_healthText;

   sf::Text m_scoreText;

   sf::Texture m_healthTexture;

   sf::Sprite m_healthSprite;

   sf::Sprite m_heatBorderSprite;

   sf::Sprite m_heatBarSprite;

   ScoreView m_scoreView;

   sf::IntRect m_heatBarRect;
};

#endif // HUDSYSTEM_H
