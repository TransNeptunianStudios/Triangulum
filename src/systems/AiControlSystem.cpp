#include "systems/AiControlSystem.h"
#include "systems/Events.h"
#include "components/Ai.h"
#include "components/Motion.h"
#include "components/Gun.h"
#include "ai/FirstBossAi.h"
#include "ai/ShootAtPlayerAi.h"
#include "ai/ShootAtPlayerWhenNearAi.h"

using namespace entityx;

AiControlSystem::AiControlSystem()
: m_aiMap()
, m_spaceShipId()
, m_scrollSpeed(0.0)
{
}

void AiControlSystem::configure(EventManager& events)
{
   events.subscribe<EvReportScrollSpeed>(*this);
   events.subscribe<EvReportSpaceShipId>(*this);
   events.subscribe<ComponentAddedEvent<Ai>>(*this);
   events.subscribe<EntityDestroyedEvent>(*this);
}

void AiControlSystem::receive(const EvReportScrollSpeed& e)
{
   m_scrollSpeed = e.scrollSpeed;
}

void AiControlSystem::receive(const EvReportSpaceShipId& e)
{
   m_spaceShipId = e.spaceShipId;
}

void AiControlSystem::receive(const ComponentAddedEvent<Ai>& e)
{
   IAiSP spAi;

   switch (e.component->aiId)
   {
   case AI_ID_FIRST_BOSS:
      spAi.reset(new FirstBossAi());
      break;
   case AI_ID_SHOOT_AT_PLAYER:
      spAi.reset(new ShootAtPlayerAi());
      break;
   case AI_ID_SHOOT_AT_PLAYER_WHEN_NEAR:
      spAi.reset(new ShootAtPlayerWhenNearAi());
      break;
   default:
      break;
   }

   if (spAi.get() != nullptr)
   {
      spAi->setScrollSpeed(m_scrollSpeed);
      m_aiMap[e.entity.id()] = spAi;
   }
}

void AiControlSystem::receive(const EntityDestroyedEvent &e)
{
   m_aiMap.erase(e.entity.id());
}

void AiControlSystem::update(EntityManager& entities,
                             EventManager& events,
                             double dt)
{
   Ai::Handle ai;
   for (Entity entity : entities.entities_with_components(ai))
   {
      if (m_aiMap.find(entity.id()) != end(m_aiMap))
      {
         m_aiMap[entity.id()]->update(entity.id(),
                                      m_spaceShipId,
                                      entities,
                                      dt);
      }
   }
}
