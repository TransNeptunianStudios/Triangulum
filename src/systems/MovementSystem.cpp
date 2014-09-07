#include "systems/MovementSystem.h"

#include <iostream>

MovementSystem::MovementSystem()
: m_nodes()
{
}

void MovementSystem::addNode(const MovementSystem::Node& node)
{
   m_nodes.push_back(node);
}

void MovementSystem::update(float dt)
{
   for (auto node : m_nodes)
   {
      auto pMotion = std::get<0>(node);
      auto pPostion = std::get<1>(node);
   }
}
