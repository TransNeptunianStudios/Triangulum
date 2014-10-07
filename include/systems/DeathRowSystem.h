#ifndef DEATHROWSYSTEM_H
#define DEATHROWSYSTEM_H

#include "entityx/System.h"

class DeathRowSystem : public entityx::System<DeathRowSystem>
{
public:

   DeathRowSystem();

   void update(entityx::EntityManager& entities,
               entityx::EventManager& events,
               double dt);
};

#endif // DEATHROWSYSTEM_H
