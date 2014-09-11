#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include "entityx/System.h"

class MovementSystem : public entityx::System<MovementSystem>
{
public:

   MovementSystem();

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);
};

#endif
