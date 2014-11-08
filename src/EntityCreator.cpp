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
#include "components/Ai.h"
#include "components/Enemy.h"
#include "components/Background.h"
#include "components/Animation.h"
#include "graphics/SplashScreen.h"
#include "graphics/StartMenuView.h"
#include "graphics/PauseMenuView.h"
#include "graphics/LevelCompMenuView.h"
#include "graphics/GameCompMenuView.h"
#include "ai/FirstBossAi.h"
#include "ScreenSize.h"
#include "AnimationFactory.h"

using namespace entityx;

SplashScreenCreator::SplashScreenCreator()
{
}

void SplashScreenCreator::create(Entity entity)
{
   auto pSmv = std::make_shared<SplashScreen>();
   entity.assign<Menu>(IMenuSP(pSmv));
   entity.assign<Position>(sf::Vector2f(ScreenSize::width()/2.0, ScreenSize::height()*0.33));
}

StartMenuCreator::StartMenuCreator()
{
}

void StartMenuCreator::create(Entity entity)
{
   auto pSmv = std::make_shared<StartMenuView>();
   entity.assign<Menu>(IMenuSP(pSmv));
   entity.assign<Position>(sf::Vector2f(ScreenSize::width()/2.0, ScreenSize::height()*0.33));
}

PauseMenuCreator::PauseMenuCreator()
{
}

void PauseMenuCreator::create(Entity entity)
{
   auto pSmv = std::make_shared<PauseMenuView>();
   entity.assign<Menu>(IMenuSP(pSmv));
   entity.assign<Position>(sf::Vector2f(ScreenSize::width()/2.0, ScreenSize::height()*0.33));
}

GameOverMenuCreator::GameOverMenuCreator(int score)
: m_score(score)
{
}

void GameOverMenuCreator::create(Entity entity)
{
   auto pSmv = std::make_shared<GameCompMenuView>("Game Over", m_score);
   entity.assign<Menu>(IMenuSP(pSmv));
   entity.assign<Position>(sf::Vector2f(ScreenSize::width()/2.0, ScreenSize::height()*0.33));
}

LevelCompMenuCreator::LevelCompMenuCreator()
{
}

void LevelCompMenuCreator::create(Entity entity)
{
   auto pSmv = std::make_shared<LevelCompMenuView>();
   entity.assign<Menu>(IMenuSP(pSmv));
   entity.assign<Position>(sf::Vector2f(ScreenSize::width()/2.0, ScreenSize::height()*0.33));
}

GameCompMenuCreator::GameCompMenuCreator(int score)
: m_score(score)
{
}

void GameCompMenuCreator::create(Entity entity)
{
   auto pSmv = std::make_shared<GameCompMenuView>("Game Completed", m_score);
   entity.assign<Menu>(IMenuSP(pSmv));
   entity.assign<Position>(sf::Vector2f(ScreenSize::width()/2.0, ScreenSize::height()*0.33));
}

BackgroundCreator::BackgroundCreator(const std::string& fileName,
                                     double scrollSpeed)
: m_fileName(fileName)
, m_scrollSpeed(scrollSpeed)
{
}

void BackgroundCreator::create(Entity entity)
{
   entity.assign<Motion>(sf::Vector2f(0.0, m_scrollSpeed));
   entity.assign<Position>();
   entity.assign<Background>();
}


SpaceShipCreator::SpaceShipCreator(int score)
    : m_score(score)
{
}

void SpaceShipCreator::create(Entity entity)
{
   auto volume = Volume();
   volume.m_boxes.push_back(CollisionBox(32, 32));

   AnimationContainer ac;

   ac.addAnimation(AnimationId(AT_Movement, IdleMovementAnimation),
                   AnimationFactory::spaceShipIdleAnimation());

   ac.addAnimation(AnimationId(AT_Movement, LeftMovementAnimation),
                   AnimationFactory::spaceShipTurnLeftAnimation());

   ac.addAnimation(AnimationId(AT_Movement, RightMovementAnimation),
                   AnimationFactory::spaceShipTurnRightAnimation());

   ac.addAnimation(AnimationId(AT_Death, DestroyedDeathAnimation),
                   AnimationFactory::spaceShipDeathAnimation());

   entity.assign<SpaceShip>(m_score);
   entity.assign<PlayerControl>();
   entity.assign<Motion>();
   entity.assign<Position>(sf::Vector2f(400.0, 300.0));
   entity.assign<Gun>(sf::Vector2f(0.0, -1.0));
   entity.assign<Volume>(volume);
   entity.assign<Health>(2);
   entity.assign<AnimationContainer>(ac);
   entity.assign<Display>(sf::IntRect(32*0, 32*0, 32, 32));
}


AsteroidCreator::AsteroidCreator(const sf::Vector2f &position,
                                 const sf::Vector2f &velocity,
                                 double rotation)
: m_position(position)
, m_velocity(velocity)
, m_rotation(rotation)
{
}

void AsteroidCreator::create(Entity entity)
{
   auto volume = Volume();
   AnimationContainer ac;

   ac.addAnimation(AnimationId(AT_Death, DestroyedDeathAnimation),
                   AnimationFactory::asteroidDeathAnimation());

   volume.m_boxes.push_back(CollisionBox(32, 32));
   entity.assign<Enemy>(ET_Asteroid);
   entity.assign<Health>(10);
   entity.assign<Motion>(m_velocity, m_rotation);
   entity.assign<Position>(m_position);
   entity.assign<Volume>(volume);
   entity.assign<AnimationContainer>(ac);
   entity.assign<Display>(sf::IntRect(32*0, 32*1, 32, 32));
}

BulletCreator::BulletCreator(Entity::Id ownerId,                             
                             const sf::Vector2f &velocity,
                             const sf::Vector2f &position,
                             double heading,
                             BulletType bulletType,
                             sf::Color color)
: m_ownerId(ownerId)
, m_velocity(velocity)
, m_position(position)
, m_heading(heading)
, m_bulletType(bulletType)
, m_color(color)
{
}

void BulletCreator::create(Entity entity)
{
   Volume volume;
   sf::IntRect coord(0, 0, 32, 32);

   switch (m_bulletType)
   {
   case BT_Simple:
      volume.m_boxes.push_back(CollisionBox(4, 8));
      coord.left = 32*0;
      coord.top = 32*5;
      break;
   case BT_Asteroid:
      volume.m_boxes.push_back(CollisionBox(32, 32));
      coord.left = 32*0;
      coord.top = 32*1;
      m_color = sf::Color(255, 255, 255);
      break;
   default:
      break;
   }

   auto damage = BulletDamageTable::lookup(m_bulletType);
   entity.assign<Motion>(m_velocity);
   entity.assign<Position>(m_position, m_heading);
   entity.assign<Bullet>(m_ownerId, 10000.0, damage);
   entity.assign<Display>(coord, m_color);
   entity.assign<Volume>(volume);
}

ScoutCreator::ScoutCreator(const sf::Vector2f& position,
                                 const sf::Vector2f& velocity,
                                 AiId aiId)
 : m_position(position)
 , m_velocity(velocity)
 , m_aiId(aiId)
{
}

void ScoutCreator::create(Entity entity)
{

    Gun gun(sf::Vector2f(0.0, 1.0));
    gun.bulletType = BT_Simple;
    auto volume = Volume();
    AnimationContainer ac;

    ac.addAnimation(AnimationId(AT_Movement, IdleMovementAnimation),
                    AnimationFactory::scoutIdleAnimation());
    ac.addAnimation(AnimationId(AT_Death, DestroyedDeathAnimation),
                    AnimationFactory::scoutDeathAnimation());

    volume.m_boxes.push_back(CollisionBox(32, 32));

    entity.assign<Enemy>(ET_Scout);
    entity.assign<Health>(5);
    entity.assign<Position>(m_position);
    entity.assign<Gun>(gun);
    entity.assign<Volume>(volume);
    entity.assign<Motion>(m_velocity);
    entity.assign<Ai>(m_aiId);
    entity.assign<AnimationContainer>(ac);
    entity.assign<Display>(sf::IntRect(32*0, 32*6, 32, 32));
}

MineCreator::MineCreator(const sf::Vector2f& position,
                                 const sf::Vector2f& velocity,
                                 AiId aiId)
 : m_position(position)
 , m_velocity(velocity)
 , m_aiId(aiId)
{
}

void MineCreator::create(Entity entity)
{

    Gun gun(sf::Vector2f(0.0, 1.0));
    gun.bulletType = BT_Simple;
    auto volume = Volume();
    AnimationContainer ac;

    ac.addAnimation(AnimationId(AT_Movement, IdleMovementAnimation),
                    AnimationFactory::mineIdleAnimation());
    /*ac.addAnimation(AnimationId(AT_Death, DestroyedDeathAnimation),
                    AnimationFactory::enemyOneDeathAnimation());
    */

    volume.m_boxes.push_back(CollisionBox(32, 32));

    entity.assign<Enemy>(ET_Mine);
    entity.assign<Health>(5);
    entity.assign<Position>(m_position);
    entity.assign<Gun>(gun);
    entity.assign<Volume>(volume);
    entity.assign<Motion>(m_velocity);
    entity.assign<Ai>(m_aiId);
    entity.assign<AnimationContainer>(ac);
    entity.assign<Display>(sf::IntRect(32*0, 32*7, 32, 32));
}

FirstBossCreator::FirstBossCreator(const sf::Vector2f& position,
                                   double scrollSpeed)
: m_position(position)
, m_scrollSpeed(scrollSpeed)
{

}

void FirstBossCreator::create(Entity entity)
{
   Gun gun(sf::Vector2f(0.0, 1.0));
   gun.bulletType = BT_Asteroid;
   auto volume = Volume();
   AnimationContainer ac;

   ac.addAnimation(AnimationId(AT_Death, DestroyedDeathAnimation),
                   AnimationFactory::asteroidBossDeathAnimation());

   volume.m_boxes.push_back(CollisionBox(96, 96));
   entity.assign<Ai>(AI_ID_FIRST_BOSS);
   entity.assign<Enemy>(ET_Boss);
   entity.assign<Health>(30, 10000.0);
   entity.assign<Motion>();
   entity.assign<Position>(m_position);
   entity.assign<Gun>(gun);
   entity.assign<Volume>(volume);
   entity.assign<AnimationContainer>(ac);
   entity.assign<Display>(sf::IntRect(32*7, 32*0, 96, 96));
}


