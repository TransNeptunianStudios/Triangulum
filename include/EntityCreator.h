#ifndef ENTITYCREATOR_H
#define ENTITYCREATOR_H

#include "entityx/Entity.h"
#include "utils/Vector2.h"
#include "ICreatable.h"

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
                 const Vector2& velocity);

   void create(entityx::Entity entity);

private:

   Vector2 m_position;

   Vector2 m_velocity;
};

#endif // ENTITYCREATOR_H
