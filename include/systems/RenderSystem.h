#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <tuple>
#include <vector>

class Position;
class Display;

class RenderSystem
{
public:

   typedef std::tuple<Position*, Display*> Node;

   RenderSystem();

   void addNode(const RenderSystem::Node& node);

   void update();

private:

   std::vector<RenderSystem::Node> m_nodes;

};

#endif // RENDERSYSTEM_H
