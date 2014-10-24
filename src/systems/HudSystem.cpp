#include "systems/HudSystem.h"
#include "graphics/FontRepository.h"
#include "components/SpaceShip.h"
#include "components/Health.h"
#include "components/DeathSentence.h"

using namespace entityx;

HudSystem::HudSystem(sf::RenderWindow& window)
: m_window(window)
, m_healthText()
, m_scoreText()
, m_healthTexture()
, m_healthSprite()
, m_scoreView(FontRepository::getHudFont(), 30)
{
   m_healthText.setFont(FontRepository::getHudFont());
   m_healthText.setCharacterSize(30);
   m_healthText.setString("Health");

   m_scoreText.setFont(FontRepository::getHudFont());
   m_scoreText.setCharacterSize(30);
   m_scoreText.setString("Score");
   m_scoreText.setOrigin(m_scoreText.getLocalBounds().width, 0.0);

   m_scoreView.setAlign(2);

   m_healthTexture.loadFromFile("../images/health.png");
   m_healthSprite.setTexture(m_healthTexture);
}

void HudSystem::update(EntityManager& entities,
                       EventManager& events,
                       double dt)
{
   SpaceShip::Handle spaceShip;
   Health::Handle health;
   for (Entity entity : entities.entities_with_components(spaceShip, health))
   {      
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
