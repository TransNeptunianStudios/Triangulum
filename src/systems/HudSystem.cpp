#include "systems/HudSystem.h"
#include "components/SpaceShip.h"
#include "components/Health.h"

using namespace entityx;

HudSystem::HudSystem()
: m_healtText()
, m_scoreText()
, m_health()
, m_scoreView(1000)
{
   m_healtText.load("Health",
                 "../resources/fonts/munro_small.ttf",
                 { 255, 255, 255, 255},
                 30);

   m_scoreText.load("Score",
                "../resources/fonts/munro_small.ttf",
                { 255, 255, 255, 255},
                30);

   m_scoreText.setTextAlignment(TA_Right);

   m_health.load("../images/health.png");
}

void HudSystem::update(EntityManager& entities,
                       EventManager& events,
                       double dt)
{
   SpaceShip::Handle spaceShip;
   Health::Handle health;
   for (Entity entity : entities.entities_with_components(spaceShip, health))
   {
      glPushMatrix();

      glTranslatef(50.f, 500.f, 0.f);

      m_healtText.draw();

      glTranslatef(8.f, 25.f, 0.f);

      for (int i = 0; i < health->health+1; ++i)
      {
         m_health.draw();

         glTranslatef(25.f, 0.f, 0.f);

      }

      glPopMatrix();

      glPushMatrix();

      glTranslatef(750.f, 500.f, 0.f);

      m_scoreText.draw();

      glPopMatrix();

      glPushMatrix();

      glTranslatef(675.f, 525.f, 0.f);

      m_scoreView.draw(spaceShip->score);

      glPopMatrix();

      // Only support one space ship atm
      return;
   }
}
