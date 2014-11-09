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

   HudSystem(sf::RenderWindow& window);

   void update(entityx::EntityManager& entities,
               entityx::EventManager& events,
               double dt);

private:

   sf::RenderWindow& m_window;

   sf::Text m_healthText;

   sf::Text m_scoreText;

   sf::Texture m_healthTexture;

   sf::Sprite m_healthSprite;

   ScoreView m_scoreView;

   ScoreView m_heatView;
};

#endif // HUDSYSTEM_H
