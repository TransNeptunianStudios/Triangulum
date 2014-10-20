#include "systems/CollisionSystem.h"
#include "systems/Events.h"
#include "components/SpaceShip.h"
#include "components/Bullet.h"
#include "components/Health.h"
#include "components/Animation.h"
#include "components/DeathSentence.h"
#include "components/PlayerControl.h"
#include "components/Gun.h"
#include "components/Display.h"
#include "components/Motion.h"
#include "AnimationFactory.h"

using namespace entityx;

CollisionSystem::CollisionSystem()
{
}

void CollisionSystem::update(EntityManager& entities,
                             EventManager& events,
                             double dt)
{
   // Spaceships hitting enemies
   SpaceShip::Handle spaceShip;
   Enemy::Handle enemy;
   Position::Handle spaceShipPos, enemyPos;
   Volume::Handle spaceShipVol, enemyVol;
   Health::Handle spaceShipHealth;
   for (Entity spaceShipEntity : entities.entities_with_components(spaceShip, spaceShipPos, spaceShipVol, spaceShipHealth))
   {
      if (spaceShipEntity.has_component<DeathSentence>())
      {
         break;
      }

      if (spaceShipHealth->isInvulnerable())
      {
         spaceShipHealth->invulnerableTime -= dt;
      }
      else
      {
         for (Entity enemyEntity : entities.entities_with_components(enemy, enemyPos, enemyVol))
         {
            if (checkCollision(spaceShipPos.get(),
                               spaceShipVol.get(),
                               enemyPos.get(),
                               enemyVol.get()))
            {
               spaceShipDamaged(spaceShipEntity, events);
               return;
            }
         }
      }
   }

   // Bullets hitting things
   Bullet::Handle bullet;
   Position::Handle bulletPos;
   Volume::Handle bulletVol;
   Health::Handle health;
   for (Entity bulletEntity : entities.entities_with_components(bullet, bulletPos, bulletVol))
   {
      // Bullets hitting spaceships
      for (Entity spaceShipEntity : entities.entities_with_components(spaceShip, spaceShipPos, spaceShipVol, spaceShipHealth))
      {
         if (spaceShipEntity.has_component<DeathSentence>() || bullet->ownerId == spaceShipEntity.id())
         {
            break;
         }

         if (spaceShipHealth->isInvulnerable())
         {
            spaceShipHealth->invulnerableTime -= dt;
         }
         else
         {
            if (checkCollision(bulletPos.get(),
                               bulletVol.get(),
                               spaceShipPos.get(),
                               spaceShipVol.get()))
            {
                bulletEntity.destroy();
                spaceShipDamaged(spaceShipEntity, events);
                return;
            }
         }
      }      
      // Bullets hitting Enemies
      for (Entity enemyEntity : entities.entities_with_components(enemy, enemyPos, enemyVol, health))
      {
         if ( enemyEntity.has_component<DeathSentence>() || bullet->ownerId == enemyEntity.id())
         {
            break;
         }

         if (checkCollision(bulletPos.get(),
                            bulletVol.get(),
                            enemyPos.get(),
                            enemyVol.get()))
         {
             bulletEntity.destroy();

             if (health->isInvulnerable())
             {
                health->invulnerableTime -= dt;
             }
             else
             {
                if( health->health == 0 )
                {
                    spaceShip->score += enemy->value;
                }

                enemyDamaged(enemyEntity, events);
             }

             return;
         }
      }
   }
}

bool CollisionSystem::checkCollision(Position* pos1,
                                     Volume* vol1,
                                     Position* pos2,
                                     Volume* vol2)
{
   for (auto box1 : vol1->m_boxes)
   {
      box1.setObjectPosition(pos1->position);

      for (auto box2 : vol2->m_boxes)
      {
        box2.setObjectPosition(pos2->position);

        if (box1.checkCollision(box2))
        {
          return true;
        }
      }
   }

   return false;
}

void CollisionSystem::spaceShipDamaged(Entity& spaceShip,
                                       EventManager& events)
{
   Health::Handle health = spaceShip.component<Health>();
   Display::Handle display = spaceShip.component<Display>();

   if (health->health == 0)
   {
      AnimationContainer::Handle acHandle = spaceShip.component<AnimationContainer>();

      acHandle->resetAnimation(AT_Movement);

      acHandle->setAnimation(AnimationId(AT_Death, DestroyedDeathAnimation));

      spaceShip.assign<DeathSentence>(2000.0);
   }
   else
   {
      health->health -= 1;
      health->invulnerableTime = 2000.0;
      display->blink.startBlink(2000.0);
   }

   events.emit<EvPlaySound>(SHIP_EXPLOSION);
}

void CollisionSystem::enemyDamaged(Entity& enemyEntity,
                                   EventManager& events)
{
   Health::Handle health = enemyEntity.component<Health>();
   Enemy::Handle enemy = enemyEntity.component<Enemy>();

   if (health->health == 0)
   {
      enemyEntity.component<Volume>().remove();
      if(enemyEntity.has_component<Gun>())
          enemyEntity.component<Gun>().remove();

      AnimationContainer::Handle acHandle = enemyEntity.component<AnimationContainer>();

      acHandle->resetAnimation(AT_Movement);

      acHandle->setAnimation(AnimationId(AT_Death, DestroyedDeathAnimation));

      events.emit<EvPlaySound>(getDeathSound(enemy->type));

      if (enemy->type == ET_Boss)
      {
         enemyEntity.component<Motion>().remove();
         enemyEntity.assign<DeathSentence>(5000.0);
      }
      else
      {
          enemyEntity.assign<DeathSentence>(700.0);
      }
   }
   else
   {
      health->health -= 1;
      events.emit<EvPlaySound>(getHitSound(enemy->type));
   }
}

SoundId CollisionSystem::getHitSound(EnemyType type)
{
   SoundId soundId = NO_SOUND;

   switch (type) {
   case ET_Asteroid:
   case ET_Boss:
      soundId = ASTEROID_HIT;
      break;
   default:
      break;
   }

   return soundId;
}

SoundId CollisionSystem::getDeathSound(EnemyType type)
{
   SoundId soundId = NO_SOUND;

   switch (type) {
   case ET_Asteroid:
   case ET_Boss:
      soundId = ASTEROID_EXPLOSION;
      break;
   default:
      break;
   }

   return soundId;
}
