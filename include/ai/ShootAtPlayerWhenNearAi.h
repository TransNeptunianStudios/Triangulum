#ifndef DIEWHENPLAYERISNEARAI_H
#define DIEWHENPLAYERISNEARAI_H

#include "ai/IAi.h"

class DieWhenPlayerIsNearAI : public IAi
{
public:

   DieWhenPlayerIsNearAI();

   void setScrollSpeed(double scrollSpeed);

   void update(entityx::Entity::Id myEntityId,
               entityx::Entity::Id enemyEntityId,
               entityx::EntityManager& entities,
               double dt);

private:

   const double m_distanceThreshold;
   const double m_timeThreshold;
   
   double m_timeClose;
};

#endif //DIEWHENPLAYERISNEARAI_H
