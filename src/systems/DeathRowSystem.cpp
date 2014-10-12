#include "systems/DeathRowSystem.h"
#include "systems/Events.h"
#include "components/DeathSentence.h"
#include "components/SpaceShip.h"
#include "components/Ai.h"

using namespace entityx;

DeathRowSystem::DeathRowSystem()
{
}

void DeathRowSystem::update(EntityManager& entities,
                            EventManager& events,
                            double dt)
{
   DeathSentence::Handle deathSentence;
   for (Entity entity : entities.entities_with_components(deathSentence))
   {
      if (deathSentence->timeToExecution <= 0.0)
      {
         const bool isSpaceShip = entity.has_component<SpaceShip>();
         const bool isBoss = entity.has_component<Ai>();

         entity.destroy();

         if (isSpaceShip)
         {
            events.emit<EvGameOver>();
         }
         else if(isBoss)
         {
             events.emit<EvBossKilled>();
         }
      }
      else
      {
         deathSentence->timeToExecution -= dt;
      }
   }

}

