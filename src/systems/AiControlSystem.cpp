#include "systems/AiControlSystem.h"
#include "systems/Events.h"
#include "components/Ai.h"
#include "components/Motion.h"
#include "components/Gun.h"
#include "ai/FirstBossAi.h"

using namespace entityx;

AiControlSystem::AiControlSystem()
: m_aiMap()
, m_spaceShipId()
{
   m_aiMap[AI_ID_FIRST_BOSS] = IAiSP(new FirstBossAi());
}

void AiControlSystem::configure(EventManager& events)
{
   events.subscribe<EvReportScrollSpeed>(*this);
   events.subscribe<EvReportSpaceShipId>(*this);
}

void AiControlSystem::receive(const EvReportScrollSpeed& e)
{
   for (auto& p : m_aiMap)
   {
      p.second->setScrollSpeed(e.scrollSpeed);
   }
}

void AiControlSystem::receive(const EvReportSpaceShipId& e)
{
   m_spaceShipId = e.spaceShipId;
}

void AiControlSystem::update(EntityManager& entities,
                             EventManager& events,
                             double dt)
{
   Ai::Handle ai;
   for (Entity entity : entities.entities_with_components(ai))
   {
      m_aiMap[ai->aiId]->update(entity.id(),
                                m_spaceShipId,
                                entities,
                                dt);
   }
}
