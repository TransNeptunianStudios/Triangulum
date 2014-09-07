#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include <vector>
#include <tuple>

#include "components/Motion.h"
#include "components/Position.h"

class MovementSystem
{
public:

   typedef std::tuple<Motion*,
                      Position*> Node;

   MovementSystem();

   void addNode(const MovementSystem::Node& node);

   void update(float dt);

private:

   std::vector<MovementSystem::Node> m_nodes;
};

#endif
