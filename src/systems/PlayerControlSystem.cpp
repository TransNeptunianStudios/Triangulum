#include "systems/PlayerControlSystem.h"
#include "components/PlayerMotionControl.h"
#include "components/Motion.h"
#include "KeyHandler.h"

using namespace entityx;

PlayerControlSystem::PlayerControlSystem(const KeyHandler& keyHandler)
: m_keyHandler(keyHandler)
{ 
}

void PlayerControlSystem::update(EntityManager &entities,
                                 EventManager &events,
                                 double dt)
{
   float vel = 200.0f;

   PlayerMotionControl::Handle playerControl;
   Motion::Handle motion;
   for (Entity entity : entities.entities_with_components(playerControl, motion))
   {
      if (m_keyHandler.isPressed(playerControl->right))
      {
         motion->velocity.x() = vel;
      }
      else if (m_keyHandler.isPressed(playerControl->left))
      {
         motion->velocity.x() = -vel;
      }
      else
      {
         motion->velocity.x() = 0.0f;
      }

      if (m_keyHandler.isPressed(playerControl->up))
      {
         motion->velocity.y() = -vel;
      }
      else if (m_keyHandler.isPressed(playerControl->down))
      {
         motion->velocity.y() = vel;
      }
      else
      {
         motion->velocity.y() = 0.0f;
      }
   }
}
