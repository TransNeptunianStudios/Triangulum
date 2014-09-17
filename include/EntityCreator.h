#ifndef ENTITYCREATOR_H
#define ENTITYCREATOR_H

#include "entityx/Entity.h"
#include "utils/Vector2.h"

class EntityCreator
{
public:

   EntityCreator(entityx::EntityManager& entityManager);

   void createBackground() const;

   void createSpaceShip() const;

   void createBullet(const Vector2& position, const Vector2& velocity) const;

private:

   entityx::EntityManager& m_entityManager;

};

#endif // ENTITYCREATOR_H
