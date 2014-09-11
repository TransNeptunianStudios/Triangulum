#include "systems/PlayerControlSystem.h"
#include "components/PlayerMotionControl.h"
#include "components/Motion.h"

using namespace entityx;

PlayerControlSystem::PlayerControlSystem(KeyHandler* pKeyHandler)
: m_pKeyHandler(pKeyHandler)
{ 
}

void PlayerControlSystem::update(EntityManager &entities,
                                 EventManager &events,
                                 double dt)
{
   PlayerMotionControl::Handle playerControl;
   Motion::Handle motion;
   for (Entity entity : entities.entities_with_components(playerControl, motion))
   {
      if (m_pKeyHandler->isPressed(playerControl.get()->right))
      {
         motion.get()->velocity.x() = 0.3f;
      }
      else if (m_pKeyHandler->isPressed(playerControl.get()->left))
      {
         motion.get()->velocity.x() = -0.3f;
      }
      else
      {
         motion.get()->velocity.x() = 0.0f;
      }
   }
}
