#ifndef LEVELSYSTEM_H
#define LEVELSYSTEM_H

#include "entityx/System.h"
#include "entityx/Event.h"
#include "systems/Events.h"
#include "utils/LevelLoader.h"
#include "EntityCreator.h"


class LevelSystem
      : public entityx::System<LevelSystem>
      , public entityx::Receiver<EvInit>
{
public:

   LevelSystem(entityx::EntityManager& entities,
               entityx::EventManager& eventManager);

   void configure(entityx::EventManager& eventManager);

   void update(entityx::EntityManager& entities,
               entityx::EventManager& events,
               double dt);

   void receive(const EvInit& e);

private:

   typedef std::pair<double, ICreatableSP> CreatablePair;

   typedef std::list<CreatablePair> CreatableList;

   struct SortCreatables
   {
      bool operator() (CreatablePair& p1,
                       CreatablePair& p2)
      {
         return p1.first < p2.first;
      }
   };

   void addObstacle(const ObstacleData& obstacle);

   void addEnemy(const EnemyData& enemy);

   void addBoss(const BossData& boss, entityx::Entity::Id spaceShipId);

   entityx::EntityManager& m_entityManager;

   entityx::EventManager& m_eventManager;

   double m_scrollSpeed;

   double m_levelOffset;

   CreatableList m_creatables;

   CreatableList m_bosses;
};

#endif // LEVELSYSTEM_H
