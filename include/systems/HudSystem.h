#ifndef HUDSYSTEM_H
#define HUDSYSTEM_H

#include "entityx/System.h"
#include "entityx/Event.h"
#include "utils/TextTexture.h"
#include "utils/Texture.h"
#include "graphics/ScoreView.h"

class HudSystem
      : public entityx::System<HudSystem>
{
public:

   HudSystem();

   void update(entityx::EntityManager& entities,
               entityx::EventManager& events,
               double dt);

private:

   TextTexture m_healtText;

   TextTexture m_scoreText;

   Texture m_health;

   ScoreView m_scoreView;
};

#endif // HUDSYSTEM_H
