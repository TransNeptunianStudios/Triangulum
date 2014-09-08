
#include "systems/PlayerControlSystem.h"
#include "components/PlayerMotionControl.h"
#include "components/Motion.h"
#include "KeyHandler.h"

PlayerControlSystem::PlayerControlSystem()
: m_node()
{ 
}

void PlayerControlSystem::addNode(const PlayerControlSystem::Node& node)
{
   m_node = node;
}

void PlayerControlSystem::update(const KeyHandler& keyHandler)
{
   auto pPlayerControl = std::get<0>(m_node);
   auto pMotion = std::get<1>(m_node);

   if (keyHandler.isPressed(SDLK_a))
   {
      pMotion->x = -0.3f;
   }
   else if (keyHandler.isPressed(SDLK_d))
   {
      pMotion->x = 0.3f;
   }
   else
   {
       pMotion->x = 0.0f;
       pMotion->y = 0.0f;
   }
}
