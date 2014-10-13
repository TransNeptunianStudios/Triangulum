#include "systems/LevelSystem.h"
#include "utils/LevelLoader.h"
#include "ScreenSize.h"

using namespace entityx;

LevelSystem::LevelSystem(EntityManager& entities,
                         EventManager& eventManager)
: m_entityManager(entities)
, m_eventManager(eventManager)
, m_scrollSpeed(50.0)
, m_levelOffset(0.0)
, m_creatables()
, m_bosses()
{
}

void LevelSystem::configure(EventManager &eventManager)
{
   eventManager.subscribe<EvInit>(*this);
}

void LevelSystem::update(EntityManager& entities,
                         EventManager& events,
                         double dt)
{
   m_levelOffset += m_scrollSpeed * dt / 1000.0;

   if (!m_creatables.empty())
   {
      if (m_levelOffset >= m_creatables.front().first)
      {
         m_creatables.front().second->create(entities.create());
         m_creatables.pop_front();
      }
   }

   if (!m_bosses.empty())
   {
      if (m_levelOffset >= m_bosses.front().first)
      {
         m_bosses.front().second->create(entities.create());
         m_bosses.pop_front();
      }
   }
}

void LevelSystem::receive(const EvInit& e)
{
   m_levelOffset = 0.0;
   m_creatables.clear();
   m_bosses.clear();

   m_eventManager.emit<EvResetAi>();

   LevelData level;

   if (!LevelLoader::load(e.levelNr, level))
   {
      return;
   }

   m_scrollSpeed = level.scrollSpeed;

   m_eventManager.emit<EvReportScrollSpeed>(m_scrollSpeed);

   BackgroundCreator(level.background.fileName,
                     level.background.scrollSpeed).create(m_entityManager.create());

   Entity spaceShipEntity = m_entityManager.create();

   SpaceShipCreator().create(spaceShipEntity);

   m_eventManager.emit<EvReportSpaceShipId>(spaceShipEntity.id());

   for (auto& obstacle : level.obstacles)
   {
      addObstacle(obstacle);
   }

   for (auto& enemy : level.enemies)
   {
      addEnemy(enemy);
   }

   SortCreatables sortFunctor;

   m_creatables.sort(sortFunctor);

   addBoss(level.boss, spaceShipEntity.id());
}

void LevelSystem::addObstacle(const ObstacleData& obstacle)
{
   double startXPos = ScreenSize::width() * obstacle.startXPos;

   if (obstacle.type == "asteroid")
   {
      m_creatables.push_back(
         std::make_pair(
            obstacle.levelOffset,
            ICreatableSP(new AsteroidCreator(sf::Vector2f(startXPos, -16.0),
                                             obstacle.speed,
                                             obstacle.rotation))));
   }
}

void LevelSystem::addEnemy(const EnemyData &enemy)
{
}

void LevelSystem::addBoss(const BossData& boss, Entity::Id spaceShipId)
{
   double offset = m_creatables.back().first + 500.0;

   if (boss.type == "big_asteroid")
   {
      m_bosses.push_back(
         std::make_pair(offset,
                        ICreatableSP(new FirstBossCreator(spaceShipId,
                                                          sf::Vector2f(400.0, -48.0),
                                                          m_scrollSpeed))));
   }
}
