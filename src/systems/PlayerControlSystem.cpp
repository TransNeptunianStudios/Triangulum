
#include "systems/PlayerControlSystem.h"
#include "KeyHandler.h"

// TBR
#include <iostream>

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
   if (keyHandler.isPressed(SDLK_a))
   {
      std::cout << "Moving left" << std::endl;
   }
   else if (keyHandler.isPressed(SDLK_d))
   {
      std::cout << "Moving right" << std::endl;
   }
}
