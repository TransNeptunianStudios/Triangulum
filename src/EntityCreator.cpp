#include "EntityCreator.h"
#include "components/PlayerControl.h"
#include "components/Motion.h"
#include "components/Position.h"
#include "components/Display.h"
#include "components/Gun.h"
#include "components/Bullet.h"
#include "components/Volume.h"
#include "components/SpaceShip.h"
#include "components/Obstacle.h"
#include "components/Health.h"
#include "components/Menu.h"
#include "components/AiControl.h"
#include "components/Enemy.h"
#include "components/Background.h"
#include "components/Animation.h"
#include "graphics/BackgroundView.h"
#include "graphics/StartMenuView.h"
#include "graphics/PauseMenuView.h"
#include "graphics/GameOverMenuView.h"
#include "graphics/LevelCompMenuView.h"
#include "ai/FirstBossAi.h"
#include "SpriteSheet.h"
#include "ScreenSize.h"
#include "AnimationFactory.h"

using namespace entityx;

StartMenuCreator::StartMenuCreator()
{
}

void StartMenuCreator::create(Entity entity)
{
   auto pSmv = std::make_shared<StartMenuView>();
   entity.assign<Menu>(IMenuSP(pSmv));
   entity.assign<Position>(Vector2(ScreenSize::width()/2.0, ScreenSize::height()*0.33));
}

PauseMenuCreator::PauseMenuCreator()
{
}

void PauseMenuCreator::create(Entity entity)
{
   auto pSmv = std::make_shared<PauseMenuView>();
   entity.assign<Menu>(IMenuSP(pSmv));
   entity.assign<Position>(Vector2(ScreenSize::width()/2.0, ScreenSize::height()*0.33));
}

GameOverMenuCreator::GameOverMenuCreator()
{
}

void GameOverMenuCreator::create(Entity entity)
{
   auto pSmv = std::make_shared<GameOverMenuView>();
   entity.assign<Menu>(IMenuSP(pSmv));
   entity.assign<Position>(Vector2(ScreenSize::width()/2.0, ScreenSize::height()*0.33));
}

LevelCompMenuCreator::LevelCompMenuCreator()
{
}

void LevelCompMenuCreator::create(Entity entity)
{
   auto pSmv = std::make_shared<LevelCompMenuView>();
   entity.assign<Menu>(IMenuSP(pSmv));
   entity.assign<Position>(Vector2(ScreenSize::width()/2.0, ScreenSize::height()*0.33));
}

BackgroundCreator::BackgroundCreator(double scrollSpeed)
: m_scrollSpeed(scrollSpeed)
{
}

void BackgroundCreator::create(Entity entity)
{
   entity.assign<Motion>(Vector2(0.0, m_scrollSpeed));
   entity.assign<Position>();
   entity.assign<Background>();
}


SpaceShipCreator::SpaceShipCreator()
{
}

void SpaceShipCreator::create(Entity entity)
{
   auto volume = Volume();
   volume.m_boxes.push_back(CollisionBox(32, 32));
   entity.assign<SpaceShip>();
   entity.assign<PlayerControl>();
   entity.assign<Motion>();
   entity.assign<Position>(Vector2(400.0, 300.0));
   entity.assign<Gun>(Vector2(0.0, -1.0));
   entity.assign<Volume>(volume);
   entity.assign<Health>(2);
   entity.assign<MovementAnimation>(AnimationFactory::spaceShipIdleAnimation());
   entity.assign<Display>(SpriteSheetCoordinate(0, 0));
}


AsteroidCreator::AsteroidCreator(const Vector2 &position,
                                 const Vector2 &velocity)
: m_position(position)
, m_velocity(velocity)
{
}

void AsteroidCreator::create(Entity entity)
{
   auto volume = Volume();
   volume.m_boxes.push_back(CollisionBox(32, 32));
   entity.assign<Enemy>(ET_Asteroid);
   entity.assign<Health>(5);
   entity.assign<Motion>(m_velocity);
   entity.assign<Position>(m_position);
   entity.assign<Volume>(volume);
   entity.assign<Display>(SpriteSheetCoordinate(0, 1));
}

BulletCreator::BulletCreator(Entity::Id ownerId,
                             const Vector2 &position,
                             const Vector2 &velocity,
                             BulletType bulletType)
: m_ownerId(ownerId)
, m_position(position)
, m_velocity(velocity)
, m_bulletType(bulletType)
{
}

void BulletCreator::create(Entity entity)
{
   auto volume = Volume();
   volume.m_boxes.push_back(CollisionBox(4, 8));
   auto damage = BulletDamageTable::lookup(m_bulletType);
   entity.assign<Motion>(m_velocity);
   entity.assign<Position>(m_position);
   entity.assign<Bullet>(m_ownerId, 10000.0, damage);
   entity.assign<Volume>(volume);
   entity.assign<Display>(SpriteSheetCoordinate(0, 5));
}

FirstBossCreator::FirstBossCreator(Entity::Id enemyId,
                                   const Vector2& position,
                                   double scrollSpeed)
: m_enemyId(enemyId)
, m_position(position)
, m_scrollSpeed(scrollSpeed)
{
}

void FirstBossCreator::create(Entity entity)
{
   auto volume = Volume();
   volume.m_boxes.push_back(CollisionBox(96, 96));
   entity.assign<AiControl>(IAiSP(new FirstBossAi(entity.id(), m_enemyId, m_scrollSpeed)));
   entity.assign<Enemy>(ET_Boss);
   entity.assign<Health>(10);
   entity.assign<Motion>();
   entity.assign<Position>(m_position);
   entity.assign<Gun>(Vector2(0.0, 1.0));
   entity.assign<Volume>(volume);
   entity.assign<Display>(SpriteSheetCoordinate(7, 0, 96));
}
