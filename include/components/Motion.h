#ifndef MOTION_H
#define MOTION_H

#include "components/Component.h"

class Motion : public Component
{
public:

   Motion();

   int velocity[2];
};

#endif