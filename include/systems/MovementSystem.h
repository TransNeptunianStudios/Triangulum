#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include <vector>

#include "systems/BaseNode.h"
#include "components/Motion.h"
#include "components/Position.h"

class MovementSystem
{
public:

   struct Node : public BaseNode
   {
      Node()
      : BaseNode(-1)
      , m_pMotion(0)
      , m_pPosition(0)
      {  
      }

      Node(Motion* pMotion,
           Position* pPosition)
      : BaseNode(pMotion->getActorId())
      , m_pMotion(pMotion)
      , m_pPosition(pPosition)
      {
      }

      Motion* m_pMotion;
      Position* m_pPosition;
   };

   MovementSystem();

   void addNode(const MovementSystem::Node& node);

   void update(float dt);

private:

   std::vector<MovementSystem::Node> m_nodes;
};

#endif