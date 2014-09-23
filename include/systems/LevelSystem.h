#ifndef LEVELSYSTEM_H
#define LEVELSYSTEM_H

#include "entityx/System.h"
#include "entityx/Event.h"
#include "systems/Events.h"
#include "EntityCreator.h"

class LevelSystem
      : public entityx::System<LevelSystem>
      , public entityx::Receiver<EvInit>
{
public:

   LevelSystem(entityx::EntityManager& entities);

   void configure(entityx::EventManager& eventManager);

   void update(entityx::EntityManager& entities,
               entityx::EventManager& events,
               double dt);

   void receive(const EvInit& e);

private:

   entityx::EntityManager& m_entityManager;

   double m_scrollSpeed;

   double m_levelOffset;

   typedef std::pair<double, ICreatableSP> CreatablePair;

   typedef std::list<CreatablePair> CreatableList;

   CreatableList m_creatables;
};

#endif // LEVELSYSTEM_H
