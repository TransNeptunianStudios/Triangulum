#include "systems/RenderSystem.h"
#include "components/Position.h"
#include "components/Display.h"

RenderSystem::RenderSystem()
: m_nodes()
{
}

void RenderSystem::addNode(const RenderSystem::Node &node)
{
   m_nodes.push_back(node);
}

void RenderSystem::update()
{
   for (auto node : m_nodes)
   {
      auto pPosition = std::get<0>(node);
      auto pDisplay = std::get<1>(node);

      // TODO: Translate to position

      pDisplay->draw();
   }
}
