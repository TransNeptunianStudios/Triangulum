#ifndef COLLISIONSYSTEM_H
#define COLLISIONSYSTEM_H

#include "SDL_rect.h"

#include "entityx/System.h"
#include "components/Position.h"
#include "components/Volume.h"

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
};

#endif // COLLISIONSYSTEM_H
