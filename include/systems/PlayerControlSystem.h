#ifndef PLAYERCONTROLSYSTEM_H
#define PLAYERCONTROLSYSTEM_H

#include <tuple>

#include "components/PlayerMotionControl.h"
#include "components/Motion.h"

class KeyHandler;

class PlayerControlSystem
{
public:

   typedef std::tuple<PlayerMotionControl*,
                      Motion*> Node;

   PlayerControlSystem();

   void addNode(const PlayerControlSystem::Node& node);

   void update(const KeyHandler& keyHandler);

private:

   PlayerControlSystem::Node m_node;
};

#endif
