#include "systems/LevelSystem.h"

using namespace entityx;

LevelSystem::LevelSystem(EntityManager& entities)
: m_entityManager(entities)
, m_scrollSpeed(50.0)
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
   m_scrollSpeed = 50.0;
   m_levelOffset = 0.0;
   m_creatables.clear();

   BackgroundCreator(0.02).create(m_entityManager.create());
   SpaceShipCreator().create(m_entityManager.create());

   m_creatables.push_back(
      std::make_pair(300.0,
                     ICreatableSP(new AsteroidCreator(Vector2(200.0, -16.0),
                                                      Vector2(0.0, m_scrollSpeed)))));
   m_creatables.push_back(
      std::make_pair(500.0,
                     ICreatableSP(new AsteroidCreator(Vector2(600.0, -16.0),
                                                      Vector2(0.0, m_scrollSpeed)))));

   m_creatables.push_back(
      std::make_pair(700.0,
                     ICreatableSP(new AsteroidCreator(Vector2(400.0, -16.0),
                                                      Vector2(0.0, m_scrollSpeed)))));

   m_creatables.push_back(
      std::make_pair(1000.0,
                     ICreatableSP(new AsteroidCreator(Vector2(350.0, -16.0),
                                                      Vector2(0.0, m_scrollSpeed)))));
}
