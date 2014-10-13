#ifndef ENTITYCREATOR_H
#define ENTITYCREATOR_H

#include "entityx/Entity.h"
#include "systems/BulletType.h"
#include "SFML/System/Vector2.hpp"
#include "ICreatable.h"

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

   GameOverMenuCreator();

   void create(entityx::Entity entity);
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

   GameCompMenuCreator();

   void create(entityx::Entity entity);
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

   SpaceShipCreator();

   void create(entityx::Entity entity);
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
                 const sf::Vector2f &position,
                 const sf::Vector2f &velocity,
                 BulletType bulletType);

   void create(entityx::Entity entity);

private:

   entityx::Entity::Id m_ownerId;

   sf::Vector2f m_position;

   sf::Vector2f m_velocity;

   BulletType m_bulletType;
};

class FirstBossCreator : public ICreatable
{
public:

   FirstBossCreator(entityx::Entity::Id enemyId,
                    const sf::Vector2f& position,
                    double scrollSpeed);

   void create(entityx::Entity entity);

private:

   entityx::Entity::Id m_enemyId;

   sf::Vector2f m_position;

   double m_scrollSpeed;
};

#endif // ENTITYCREATOR_H
