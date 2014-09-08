#include "systems/RenderSystem.h"
#include "components/Position.h"
#include "components/Display.h"
#include <SDL_opengl.h>

// TBR
#include <iostream>

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

      glLoadIdentity();
      glTranslatef(pPosition->x, pPosition->y, 0.f);

      pDisplay->draw();
   }
}
