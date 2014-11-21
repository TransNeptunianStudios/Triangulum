#include "systems/DeathRowSystem.h"
#include "systems/Events.h"
#include "components/DeathSentence.h"
#include "components/SpaceShip.h"
#include "components/Enemy.h"
#include "components/Animation.h"
#include "components/Gun.h"

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
       if(!deathSentence->haveBeenPrepared)
       {
           if(entity.has_component<AnimationContainer>())
           {
               AnimationContainer::Handle acHandle = entity.component<AnimationContainer>();
               acHandle->resetAnimation(AT_Movement);
               acHandle->setAnimation(AnimationId(AT_Death, DestroyedDeathAnimation));
           }
           
           if(entity.has_component<Gun>())
               entity.component<Gun>().remove();

           deathSentence->haveBeenPrepared = true;
       }
       
      if (deathSentence->timeToExecution <= 0.0)
      {
         if (entity.has_component<SpaceShip>())
         {
            entity.destroy();
            events.emit<EvGameOver>();
         }
         else
         {
            if (entity.has_component<Enemy>())
            {
               Enemy* pEnemy =  entity.component<Enemy>().get();
               if (pEnemy->type == ET_Boss)
               {
                  entity.destroy();
                  events.emit<EvBossKilled>();
               }
               else
               {
                  entity.destroy();
               }
            }
         }
      }
      else
      {
         deathSentence->timeToExecution -= dt;
      }
   }

}

