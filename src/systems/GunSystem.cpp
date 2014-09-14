#include "systems/GunSystem.h"
#include "systems/Events.h"
#include "components/PlayerMotionControl.h"
#include "components/Position.h"
#include "components/Gun.h"

using namespace entityx;

GunSystem::GunSystem(KeyHandler* pKeyHandler,
                     EntityCreator* pEntityCreator)
: m_pKeyHandler(pKeyHandler)
, m_pEntityCreator(pEntityCreator)
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
      if (m_pKeyHandler->isPressed(playerControl->shoot))
      {
         if (!gun->isShooting)
         {
            m_pEntityCreator->createBullet(position->position,
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
