#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "SDL_rect.h"

#include "entityx/System.h"
#include "components/Position.h"
#include "components/Volume.h"
#include "components/Enemy.h"
#include "SoundId.h"

class CollisionSystem : public entityx::System<CollisionSystem>
{
public:

   CollisionSystem();

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   bool checkCollision(Position* pos1,
                       Volume* vol1,
                       Position* pos2,
                       Volume* vol2);

   void spaceShipDamaged(entityx::Entity& spaceShip,
                           entityx::EventManager& events);

   void enemyDamaged(entityx::Entity& enemy,
                     entityx::EventManager& events);

   SoundId getHitSound(EnemyType type);

   SoundId getDeathSound(EnemyType type);
};

#endif // COLLISIONSYSTEM_H
