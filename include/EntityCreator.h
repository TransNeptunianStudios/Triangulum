#ifndef ENTITYCREATOR_H
#define ENTITYCREATOR_H

#include "entityx/Entity.h"
#include "systems/BulletType.h"
#include "utils/Vector2.h"
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

   AsteroidCreator(const Vector2& position,
                   const Vector2& velocity,
                   double rotation);

   void create(entityx::Entity entity);

private:

   Vector2 m_position;

   Vector2 m_velocity;

   double m_rotation;
};

class BulletCreator : public ICreatable
{
public:

   BulletCreator(entityx::Entity::Id ownerId,
                 const Vector2& position,
                 const Vector2& velocity,
                 BulletType bulletType);

   void create(entityx::Entity entity);

private:

   entityx::Entity::Id m_ownerId;

   Vector2 m_position;

   Vector2 m_velocity;

   BulletType m_bulletType;
};

class FirstBossCreator : public ICreatable
{
public:

   FirstBossCreator(entityx::Entity::Id enemyId,
                    const Vector2& position,
                    double scrollSpeed);

   void create(entityx::Entity entity);

private:

   entityx::Entity::Id m_enemyId;

   Vector2 m_position;

   double m_scrollSpeed;
};

#endif // ENTITYCREATOR_H
