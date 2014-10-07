#ifndef PLAYERCONTROLSYSTEM_H
#define PLAYERCONTROLSYSTEM_H

#include "entityx/System.h"

class KeyHandler;
class Vector2;

class PlayerControlSystem : public entityx::System<PlayerControlSystem>
{
public:

   PlayerControlSystem(const KeyHandler& keyHandler);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   void assignAnimation(const Vector2& velocity,
                        entityx::Entity& entity);

   const KeyHandler& m_keyHandler;
};

#endif
