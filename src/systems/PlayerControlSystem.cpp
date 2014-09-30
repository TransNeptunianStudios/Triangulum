#include "systems/PlayerControlSystem.h"
#include "components/PlayerControl.h"
#include "components/Motion.h"
#include "components/Gun.h"
#include "KeyHandler.h"
#include "systems/Events.h"

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

   PlayerControl::Handle playerControl;
   Motion::Handle motion;
   Gun::Handle gun;
   for (Entity entity : entities.entities_with_components(playerControl, motion, gun))
   {
      if(m_keyHandler.isPressed(playerControl->pause))
      {
          events.emit<EvPauseGame>();
      }

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

      gun->isMainFirePressed = m_keyHandler.isPressed(playerControl->shoot);
   }
}
