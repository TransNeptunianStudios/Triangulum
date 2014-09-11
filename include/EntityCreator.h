#ifndef ENTITYCREATOR_H
#define ENTITYCREATOR_H

#include "entityx/Entity.h"
#include "utils/Vector2.h"

class EntityCreator
{
public:

   EntityCreator(entityx::EntityManager& entityManager);

   void createSpaceShip();

   void createBullet(const Vector2& position, const Vector2& velocity);

private:

   entityx::EntityManager& m_entityManager;

};

#endif // ENTITYCREATOR_H
