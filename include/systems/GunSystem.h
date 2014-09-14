#ifndef GUNSYSTEM_H
#define GUNSYSTEM_H

#include "entityx/System.h"

class KeyHandler;
class EntityCreator;

class GunSystem : public entityx::System<GunSystem>
{
public:

   GunSystem(const KeyHandler& keyHandler,
             const EntityCreator& entityCreator);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   const KeyHandler& m_keyHandler;

   const EntityCreator& m_entityCreator;
};

#endif // GUNSYSTEM_H
