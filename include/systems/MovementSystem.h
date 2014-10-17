#ifndef MOVEMENTSYSTEM_H
#define MOVEMENTSYSTEM_H

#include "entityx/System.h"
#include "SFML/System/Vector2.hpp"

class MovementSystem : public entityx::System<MovementSystem>
{
public:

   MovementSystem();

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:
   bool isOnScreen(sf::Vector2f newPos, entityx::Entity &entity) const;
};

#endif
