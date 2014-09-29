#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include "entityx/System.h"
#include "utils/Vector2.h"

class MovementSystem : public entityx::System<MovementSystem>
{
public:

   MovementSystem();

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:
   bool isOnScreen(Vector2 position) const;
};

#endif
