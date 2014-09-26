#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "entityx/Entity.h"

enum ObstacleType
{
   OT_Asteroid,
};

struct Obstacle : public entityx::Component<Obstacle>
{
   Obstacle(ObstacleType _type);

   ObstacleType type;
};

#endif // OBSTACLE_H
