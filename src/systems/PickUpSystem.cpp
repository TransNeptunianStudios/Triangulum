#include "systems/PickUpSystem.h"
#include "components/Gun.h"
#include "components/Health.h"

using namespace entityx;

PickUpSystem::PickUpSystem(EntityManager& entityManager)
: m_entityManager(entityManager)
{
}

void PickUpSystem::configure(EventManager& eventManager)
{
   eventManager.subscribe<EvPickUp>(*this);
}

void PickUpSystem::receive(const EvPickUp& e)
{
   Gun::Handle gun = m_entityManager.component<Gun>(e.id);
   Health::Handle health = m_entityManager.component<Health>(e.id);
   switch (e.pickUpType)
   {
   case PUT_DOUBLE_GUN:
      break;
   case PUT_ONE_HEALTH:
      health->health += 1;
      break;
   default:
      break;
   }
}

void PickUpSystem::update(EntityManager& entities, EventManager& events, double dt)
{
}

