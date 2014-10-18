#ifndef AICONTROLSYSTEM_H
#define AICONTROLSYSTEM_H

#include <map>
#include "entityx/System.h"
#include "entityx/Event.h"
#include "systems/AiControlSystem.h"
#include "components/Ai.h"
#include "ai/IAi.h"

class EvResetAi;
class EvReportScrollSpeed;
class EvReportSpaceShipId;

class AiControlSystem
      : public entityx::System<AiControlSystem>
      , public entityx::Receiver<AiControlSystem>
{
public:

   AiControlSystem();

   void configure(entityx::EventManager& events);

   void receive(const EvReportScrollSpeed& e);

   void receive(const EvReportSpaceShipId& e);

   void receive(const entityx::ComponentAddedEvent<Ai>& e);

   void receive(const entityx::EntityDestroyedEvent& e);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   typedef std::map<entityx::Entity::Id, IAiSP> AiMap;

   AiMap m_aiMap;

   entityx::Entity::Id m_spaceShipId;

   double m_scrollSpeed;
};

#endif // AICONTROLSYSTEM_H
