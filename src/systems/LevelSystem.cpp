#include "systems/LevelSystem.h"

using namespace entityx;

LevelSystem::LevelSystem(EntityManager& entities)
: m_entityManager(entities)
, m_scrollSpeed(0.02)
, m_levelOffset(0.0)
, m_creatables()
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
}

void LevelSystem::receive(const EvInit &e)
{
   BackgroundCreator(m_scrollSpeed).create(m_entityManager.create());
   SpaceShipCreator().create(m_entityManager.create());

   m_creatables.push_back(
      std::make_pair(0.05,
                     ICreatableSP(new AsteroidCreator(Vector2(-0.3, 1.1),
                                                      Vector2(0.0, -m_scrollSpeed*20)))));
   m_creatables.push_back(
      std::make_pair(0.07,
                     ICreatableSP(new AsteroidCreator(Vector2(0.7, 1.1),
                                                      Vector2(0.0, -m_scrollSpeed*20)))));

   m_creatables.push_back(
      std::make_pair(0.08,
                     ICreatableSP(new AsteroidCreator(Vector2(0.5, 1.1),
                                                      Vector2(0.0, -m_scrollSpeed*20)))));

   m_creatables.push_back(
      std::make_pair(0.1,
                     ICreatableSP(new AsteroidCreator(Vector2(0.0, 1.1),
                                                      Vector2(0.0, -m_scrollSpeed*20)))));
}
