#include "systems/PlayerControlSystem.h"
#include "systems/Events.h"
#include "components/PlayerControl.h"
#include "components/Motion.h"
#include "components/Gun.h"
#include "components/DeathSentence.h"
#include "KeyHandler.h"
#include "AnimationFactory.h"

using namespace entityx;

PlayerControlSystem::PlayerControlSystem(const KeyHandler& keyHandler)
: m_keyHandler(keyHandler)
{ 
}

void PlayerControlSystem::update(EntityManager &entities,
                                 EventManager &events,
                                 double dt)
{
   float vel = 300.0f;

   PlayerControl::Handle playerControl;
   Motion::Handle motion;
   Gun::Handle gun;
   for (Entity entity : entities.entities_with_components(playerControl, motion, gun))
   {
      if (entity.has_component<DeathSentence>())
      {
         motion->velocity.x = 0.0;
         motion->velocity.y = 0.0;
         break;
      }

      if (m_keyHandler.isPressed(playerControl->right)
              || m_keyHandler.isPressed(playerControl->altRight))
      {
         motion->velocity.x = vel;
      }
      else if (m_keyHandler.isPressed(playerControl->left)
               || m_keyHandler.isPressed(playerControl->altLeft))
      {
         motion->velocity.x = -vel;
      }
      else
      {
         motion->velocity.x = 0.0f;
      }

      if (m_keyHandler.isPressed(playerControl->up)
              || m_keyHandler.isPressed(playerControl->altUp))
      {
         motion->velocity.y = -vel;
      }
      else if (m_keyHandler.isPressed(playerControl->down)
               || m_keyHandler.isPressed(playerControl->altDown))
      {
         motion->velocity.y = vel;
      }
      else
      {
         motion->velocity.y = 0.0f;
      }

      gun->isMainFirePressed = m_keyHandler.isPressed(playerControl->shoot);
   }
}
