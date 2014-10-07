#include "systems/CollisionSystem.h"
#include "systems/Events.h"
#include "components/SpaceShip.h"
#include "components/Bullet.h"
#include "components/Health.h"
#include "components/Animation.h"
#include "components/DeathSentence.h"
#include "AnimationFactory.h"

using namespace entityx;

CollisionSystem::CollisionSystem()
{
}

void CollisionSystem::update(EntityManager& entities,
                             EventManager& events,
                             double dt)
{
   SpaceShip::Handle spaceShip;
   Enemy::Handle enemy;
   Position::Handle spaceShipPos, enemyPos;
   Volume::Handle spaceShipVol, enemyVol;
   for (Entity spaceShipEntity : entities.entities_with_components(spaceShip, spaceShipPos, spaceShipVol))
   {
      for (Entity enemyEntity : entities.entities_with_components(enemy, enemyPos, enemyVol))
      {
         if (checkCollision(spaceShipPos.get(),
                            spaceShipVol.get(),
                            enemyPos.get(),
                            enemyVol.get()))
         {
            spaceShipDestroyed(spaceShipEntity, events);
            return;
         }
      }
   }

   Bullet::Handle bullet;
   Position::Handle bulletPos;
   Volume::Handle bulletVol;
   Health::Handle health;
   for (Entity bulletEntity : entities.entities_with_components(bullet, bulletPos, bulletVol))
   {
      for (Entity spaceShipEntity : entities.entities_with_components(spaceShip, spaceShipPos, spaceShipVol))
      {
         if (bullet->ownerId == spaceShipEntity.id())
         {
            break;
         }

         if (checkCollision(bulletPos.get(),
                            bulletVol.get(),
                            spaceShipPos.get(),
                            spaceShipVol.get()))
         {
             bulletEntity.destroy();
             spaceShipDestroyed(spaceShipEntity, events);
             return;
         }
      }

      for (Entity enemyEntity : entities.entities_with_components(enemy, enemyPos, enemyVol, health))
      {
         if (bullet->ownerId == enemyEntity.id())
         {
            break;
         }

         if (checkCollision(bulletPos.get(),
                            bulletVol.get(),
                            enemyPos.get(),
                            enemyVol.get()))
         {
             health->health -= bullet->damage;

             bulletEntity.destroy();

             SoundId soundId = NO_SOUND;

             if (health->health <= 0)
             {
                EnemyType type = enemy->type;

                enemyEntity.destroy();

                events.emit<EvPlaySound>(getDeathSound(type));

                if (type == ET_Boss)
                {
                   events.emit<EvBossKilled>();
                   return;
                }
             }
             else
             {
                events.emit<EvPlaySound>(getHitSound(enemy->type));
             }

             break;
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

void CollisionSystem::spaceShipDestroyed(entityx::Entity& spaceShip,
                                         entityx::EventManager& events)
{
   spaceShip.assign<DeathAnimation>(AnimationFactory::spaceShipDeathAnimation());
   spaceShip.assign<DeathSentence>(2000.0);
   events.emit<EvPlaySound>(SHIP_EXPLOSION);
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
