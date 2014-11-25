#ifndef PICKUPSYSTEM_H
#define PICKUPSYSTEM_H

#include "entityx/System.h"
#include "systems/Events.h"

class PickUpSystem
      : public entityx::System<PickUpSystem>
      , public entityx::Receiver<PickUpSystem>
{
public:

   PickUpSystem(entityx::EntityManager& entityManager);

   void configure(entityx::EventManager& eventManager);

   void receive(const EvPickUp& e);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   entityx::EntityManager& m_entityManager;
};

#endif // PICKUPSYSTEM_H
