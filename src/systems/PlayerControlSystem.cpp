
#include "systems/PlayerControlSystem.h"
#include "components/PlayerMotionControl.h"
#include "components/Motion.h"
#include "KeyHandler.h"

// TBR
#include "iostream"

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

   // Left and right movement
   if (keyHandler.isPressed(SDLK_a))
   {
      pMotion->velocity.x() = -0.3f;
   }
   else if (keyHandler.isPressed(SDLK_d))
   {
      pMotion->velocity.x() = 0.3f;
   }
   else
   {
       pMotion->velocity.x() = 0.0f;
   }

   // Up and down movement
   if (keyHandler.isPressed(SDLK_w))
   {
      pMotion->velocity.y() = 0.3f;
   }
   else if (keyHandler.isPressed(SDLK_s))
   {
      pMotion->velocity.y() = -0.3f;
   }
   else
   {
       pMotion->velocity.y() = 0.0f;
   }

   // Fire
   if (keyHandler.isPressed(SDLK_SPACE))
   {
        std::cout << "Pew pew!" << std::endl;
   }
}
