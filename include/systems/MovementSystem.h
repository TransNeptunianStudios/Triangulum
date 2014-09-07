#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include <tuple>
#include <vector>

class Motion;
class Position;

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
