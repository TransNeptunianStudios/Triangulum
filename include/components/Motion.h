#ifndef MOTION_H
#define MOTION_H

#include "components/Component.h"
#include "utils/Vector2.h"

class Motion : public Component
{
public:

   Motion();

   Vector2 velocity;
};

#endif
