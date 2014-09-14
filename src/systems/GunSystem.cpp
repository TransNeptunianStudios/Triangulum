#include "systems/GunSystem.h"
#include "systems/Events.h"
#include "components/PlayerMotionControl.h"
#include "components/Position.h"
#include "components/Gun.h"
#include "KeyHandler.h"
#include "EntityCreator.h"

using namespace entityx;

GunSystem::GunSystem(const KeyHandler& keyHandler,
                     const EntityCreator& entityCreator)
: m_keyHandler(keyHandler)
, m_entityCreator(entityCreator)
{
}

void GunSystem::update(EntityManager &entities,
                       EventManager &events,
                       double dt)
{
   PlayerMotionControl::Handle playerControl;
   Position::Handle position;
   Gun::Handle gun;
   for (Entity entity : entities.entities_with_components(playerControl, position, gun))
   {
      if (m_keyHandler.isPressed(playerControl->shoot))
      {
         if (!gun->isShooting)
         {
            m_entityCreator.createBullet(position->position,
                                         Vector2(0.0, 0.6));

            events.emit<PlaySound>(GUN_SHOOT);

            gun->isShooting = true;
         }
      }
      else
      {
         gun->isShooting = false;
      }
   }
}
