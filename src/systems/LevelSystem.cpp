#include "systems/LevelSystem.h"

using namespace entityx;

LevelSystem::LevelSystem(EntityManager& entities)
: m_entityManager(entities)
, m_scrollSpeed(0.02)
, m_levelOffset(0.0)
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
}

void LevelSystem::receive(const EvInit &e)
{
   BackgroundCreator(m_scrollSpeed).create(m_entityManager.create());
   SpaceShipCreator().create(m_entityManager.create());
}
