#include "EntityCreator.h"
#include "components/PlayerMotionControl.h"
#include "components/Motion.h"
#include "components/Position.h"
#include "components/Animation.h"
#include "components/Display.h"
#include "components/Gun.h"
#include "components/Bullet.h"
#include "graphics/SpaceShipView.h"
#include "graphics/BulletView.h"
#include "graphics/BackgroundView.h"
#include "graphics/Asteroidview.h"
#include "SpriteSheet.h"

using namespace entityx;

BackgroundCreator::BackgroundCreator(double scrollSpeed)
: m_scrollSpeed(scrollSpeed)
{
}

void BackgroundCreator::create(Entity entity)
{
   entity.assign<Motion>(Vector2(0.0, m_scrollSpeed));
   entity.assign<Position>();
   entity.assign<Display>(IDrawableSP(new BackgroundView()));
}


SpaceShipCreator::SpaceShipCreator()
{
}

void SpaceShipCreator::create(Entity entity)
{
   auto pSpriteSheet = new SpriteSheet("../images/SpriteSheet.png", 32);
   auto pSsv = std::make_shared<SpaceShipView>( pSpriteSheet );
   entity.assign<PlayerMotionControl>();
   entity.assign<Motion>();
   entity.assign<Position>(Vector2(400.0, 300.0));
   entity.assign<Gun>();
   entity.assign<Animation>(IAnimatibleSP(pSsv));
   entity.assign<Display>(IDrawableSP(pSsv));
}


AsteroidCreator::AsteroidCreator(const Vector2 &position,
                                 const Vector2 &velocity)
: m_position(position)
, m_velocity(velocity)
{
}

void AsteroidCreator::create(Entity entity)
{
   auto pSpriteSheet = new SpriteSheet("../images/SpriteSheet.png", 32);
   auto pAv = new AsteroidView( pSpriteSheet );
   entity.assign<Motion>(m_velocity);
   entity.assign<Position>(m_position);
   entity.assign<Display>(IDrawableSP(pAv));
}

BulletCreator::BulletCreator(const Vector2 &position,
                             const Vector2 &velocity)
: m_position(position)
, m_velocity(velocity)
{
}

void BulletCreator::create(Entity entity)
{
   auto pBv = new BulletView();
   entity.assign<Motion>(m_velocity);
   entity.assign<Position>(m_position);
   entity.assign<Bullet>(10000.0);
   entity.assign<Display>(IDrawableSP(pBv));
}
