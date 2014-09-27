#include "systems/AiControlSystem.h"
#include "components/AiControl.h"
#include "components/Motion.h"
#include "components/Gun.h"

using namespace entityx;

AiControlSystem::AiControlSystem()
{
}

void AiControlSystem::update(EntityManager& entities,
                             EventManager& events,
                             double dt)
{
   AiControl::Handle aiControl;
   for (Entity entity : entities.entities_with_components(aiControl))
   {
      aiControl->spAi->update(entities, dt);
   }
}
