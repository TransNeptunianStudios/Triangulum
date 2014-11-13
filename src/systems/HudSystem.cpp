#include "systems/HudSystem.h"
#include "graphics/FontRepository.h"
#include "components/SpaceShip.h"
#include "components/Health.h"
#include "components/Gun.h"
#include "components/DeathSentence.h"
#include "ResourcePath.hpp"

using namespace entityx;

HudSystem::HudSystem(sf::RenderWindow& window,
                     const std::shared_ptr<sf::Texture>& spSSTexture)
: m_window(window)
, m_spSSTexture(spSSTexture)
, m_healthText()
, m_scoreText()
, m_healthTexture()
, m_healthSprite()
, m_scoreView(FontRepository::getHudFont(), 30)
, m_heatBarRect(32*0, 32*8+16, 0, 16)
{
   m_healthText.setFont(FontRepository::getHudFont());
   m_healthText.setCharacterSize(30);
   m_healthText.setString("Health");

   m_scoreText.setFont(FontRepository::getHudFont());
   m_scoreText.setCharacterSize(30);
   m_scoreText.setString("Score");
   m_scoreText.setOrigin(m_scoreText.getLocalBounds().width, 0.0);

   m_scoreView.setAlign(2);

   m_healthTexture.loadFromFile(resourcePath() + "images/health.png");
   m_healthSprite.setTexture(m_healthTexture);

   m_heatBorderSprite.setTexture(*m_spSSTexture);
   m_heatBorderSprite.setTextureRect(sf::IntRect(32*0, 32*8, 104, 16));
   m_heatBarSprite.setTexture(*m_spSSTexture);
}

void HudSystem::update(EntityManager& entities,
                       EventManager& events,
                       double dt)
{
   SpaceShip::Handle spaceShip;
   Health::Handle health;
   Gun::Handle gun;
   for (Entity entity : entities.entities_with_components(spaceShip, health, gun))
   {
      m_heatBorderSprite.setPosition(50.0f, 485.0f);
      m_window.draw(m_heatBorderSprite);

      m_heatBarSprite.setPosition(50.0f, 485.0f);
      m_heatBarRect.width = static_cast<int>(gun->heat+0.5);
      m_heatBarSprite.setTextureRect(m_heatBarRect);
      m_window.draw(m_heatBarSprite);

      m_healthText.setPosition(50.0f, 500.0f);
      m_window.draw(m_healthText);

      if (!entity.has_component<DeathSentence>())
      {
         float startX = 50.0f;
         for (int i = 0; i < health->health+1; ++i)
         {
            m_healthSprite.setPosition(startX, 540.0f);
            m_window.draw(m_healthSprite);
            startX += 25.0f;
         }
      }

      m_scoreText.setPosition(750.0f, 500.0f);

      m_window.draw(m_scoreText);

      m_scoreView.setPosition(750.0f, 533.0f);

      m_scoreView.draw(spaceShip->score, m_window);

      // Only support one space ship atm
      return;
   }
}
