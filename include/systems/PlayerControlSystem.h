#ifndef PLAYERCONTROLSYSTEM_H
#define PLAYERCONTROLSYSTEM_H

#include "systems/BaseNode.h"
#include "components/PlayerMotionControl.h"
#include "components/Motion.h"

class KeyHandler;

class PlayerControlSystem
{
public:

   struct Node : public BaseNode
   {
      Node()
      : BaseNode(-1)
      , m_pPlayerMotionControl(0)
      , m_pMotion(0)
      {
      } 

      Node(PlayerMotionControl* pPlayerMotionControl,
           Motion* pMotion)
      : BaseNode(pPlayerMotionControl->getActorId())
      , m_pPlayerMotionControl(pPlayerMotionControl)
      , m_pMotion(pMotion)
      {
      }

      PlayerMotionControl* m_pPlayerMotionControl;
      Motion* m_pMotion;
   };

   PlayerControlSystem();

   void addNode(const PlayerControlSystem::Node& node);

   void update(const KeyHandler& keyHandler);

private:

   PlayerControlSystem::Node m_node;
};

#endif
