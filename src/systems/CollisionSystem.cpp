#include "systems/CollisionSystem.h"
#include "systems/Events.h"
#include "components/SpaceShip.h"
#include "components/Bullet.h"
#include "components/Health.h"

using namespace entityx;

CollisionSystem::CollisionSystem()
{
}

void CollisionSystem::update(EntityManager& entities,
                             EventManager& events,
                             double dt)
{
   SpaceShip::Handle spaceShip;
   Obstacle::Handle obstacle;
   Position::Handle spaceShipPos, obstaclePos;
   Volume::Handle spaceShipVol, obstacleVol;
   for (Entity spaceShipEntity : entities.entities_with_components(spaceShip, spaceShipPos, spaceShipVol))
   {
      for (Entity obstacleEntity : entities.entities_with_components(obstacle, obstaclePos, obstacleVol))
      {
         if (checkCollision(spaceShipPos.get(),
                            spaceShipVol.get(),
                            obstaclePos.get(),
                            obstacleVol.get()))
         {
             spaceShipEntity.destroy();
             events.emit<EvPlaySound>(SHIP_EXPLOSION);
             events.emit<EvGameOver>();
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
      for (Entity obstacleEntity : entities.entities_with_components(obstacle, obstaclePos, obstacleVol, health))
      {
         if (checkCollision(bulletPos.get(),
                            bulletVol.get(),
                            obstaclePos.get(),
                            obstacleVol.get()))
         {
             health->health -= bullet->damage;

             bulletEntity.destroy();

             SoundId soundId = NO_SOUND;

             if (health->health <= 0)
             {
                soundId = getDeathSound(obstacle->type);
                obstacleEntity.destroy();
             }
             else
             {
                soundId = getHitSound(obstacle->type);
             }

             events.emit<EvPlaySound>(soundId);

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

SoundId CollisionSystem::getHitSound(ObstacleType type)
{
   SoundId soundId = NO_SOUND;

   switch (type) {
   case OT_Asteroid:
      soundId = ASTEROID_HIT;
      break;
   default:
      break;
   }

   return soundId;
}

SoundId CollisionSystem::getDeathSound(ObstacleType type)
{
   SoundId soundId = NO_SOUND;

   switch (type) {
   case OT_Asteroid:
      soundId = ASTEROID_EXPLOSION;
      break;
   default:
      break;
   }

   return soundId;
}
