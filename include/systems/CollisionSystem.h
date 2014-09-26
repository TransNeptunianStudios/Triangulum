#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "SDL_rect.h"

#include "entityx/System.h"
#include "components/Position.h"
#include "components/Volume.h"
#include "components/Obstacle.h"
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

   SoundId getHitSound(ObstacleType type);

   SoundId getDeathSound(ObstacleType type);
};

#endif // COLLISIONSYSTEM_H
