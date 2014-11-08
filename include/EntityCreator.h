#ifndef ENTITYCREATOR_H
#define ENTITYCREATOR_H

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics/Color.hpp"
#include "entityx/Entity.h"
#include "systems/BulletType.h"
#include "ICreatable.h"
#include "ai/IAi.h"

class SplashScreenCreator : public ICreatable
{
public:

   SplashScreenCreator();

   void create(entityx::Entity entity);
};

class StartMenuCreator : public ICreatable
{
public:

   StartMenuCreator();

   void create(entityx::Entity entity);
};

class PauseMenuCreator : public ICreatable
{
public:

   PauseMenuCreator();

   void create(entityx::Entity entity);
};

class GameOverMenuCreator : public ICreatable
{
public:

   GameOverMenuCreator(int score);

   void create(entityx::Entity entity);

private:

   int m_score;
};

class LevelCompMenuCreator : public ICreatable
{
public:

   LevelCompMenuCreator();

   void create(entityx::Entity entity);
};

class GameCompMenuCreator : public ICreatable
{
public:

   GameCompMenuCreator(int score);

   void create(entityx::Entity entity);

private:

   int m_score;
};

class BackgroundCreator : public ICreatable
{
public:

   BackgroundCreator(const std::string& fileName,
                     double scrollSpeed);

   void create(entityx::Entity entity);

private:

   std::string m_fileName;

   double m_scrollSpeed;
};

class SpaceShipCreator : public ICreatable
{
public:

   SpaceShipCreator(int score = 0);

   void create(entityx::Entity entity);

private:
   int m_score;
};

class AsteroidCreator : public ICreatable
{
public:

   AsteroidCreator(const sf::Vector2f &position,
                   const sf::Vector2f &velocity,
                   double rotation);

   void create(entityx::Entity entity);

private:

   sf::Vector2f m_position;

   sf::Vector2f m_velocity;

   double m_rotation;
};

class BulletCreator : public ICreatable
{
public:

   BulletCreator(entityx::Entity::Id ownerId,
                 const sf::Vector2f &velocity,
                 const sf::Vector2f &position,
                 double heading,
                 BulletType bulletType,
                 sf::Color color);

   void create(entityx::Entity entity);

private:

   entityx::Entity::Id m_ownerId;

   sf::Vector2f m_velocity;

   sf::Vector2f m_position;

   double m_heading;

   BulletType m_bulletType;

   sf::Color m_color;
};

class ScoutCreator : public ICreatable
{
public:

   ScoutCreator(const sf::Vector2f& position,
                   const sf::Vector2f& velocity,
                   AiId aiId);

   void create(entityx::Entity entity);

private:

   sf::Vector2f m_position;

   sf::Vector2f m_velocity;

   AiId m_aiId;
};

class MineCreator : public ICreatable
{
public:

   MineCreator(const sf::Vector2f& position,
                   const sf::Vector2f& velocity,
                   AiId aiId);

   void create(entityx::Entity entity);

private:

   sf::Vector2f m_position;

   sf::Vector2f m_velocity;

   AiId m_aiId;
};

class FirstBossCreator : public ICreatable
{
public:

   FirstBossCreator(const sf::Vector2f& position,
                    double scrollSpeed);

   void create(entityx::Entity entity);

private:

   sf::Vector2f m_position;

   double m_scrollSpeed;
};

#endif // ENTITYCREATOR_H
