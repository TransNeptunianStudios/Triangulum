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

class GameOverMenuCreator : public ICreatable
{
public:

   GameOverMenuCreator();

   void create(entityx::Entity entity);
};

class BackgroundCreator : public ICreatable
{
public:

   BackgroundCreator(double scrollSpeed);

   void create(entityx::Entity entity);

private:

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
                   const Vector2& velocity);

   void create(entityx::Entity entity);

private:

   Vector2 m_position;

   Vector2 m_velocity;
};

class BulletCreator : public ICreatable
{
public:

   BulletCreator(const Vector2& position,
                 const Vector2& velocity,
                 BulletType bulletType);

   void create(entityx::Entity entity);

private:

   Vector2 m_position;

   Vector2 m_velocity;

   BulletType m_bulletType;
};

#endif // ENTITYCREATOR_H
