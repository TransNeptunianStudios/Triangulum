#include "systems/BulletLifeTimeSystem.h"
#include "components/Bullet.h"

using namespace entityx;

BulletLifeTimeSystem::BulletLifeTimeSystem()
{
}

void BulletLifeTimeSystem::update(EntityManager &entities,
                                  EventManager &events,
                                  double dt)
{
   Bullet::Handle bullet;
   for (Entity entity : entities.entities_with_components(bullet))
   {
      bullet->age += dt;
      if (bullet->age > bullet->lifeTime)
      {
         entity.destroy();
      }
   }
}
