#ifndef POSITION_H
#define POSITION_H

#include "components/Component.h"
#include "utils/Vector2.h"

class Position : public Component
{
public:

   Position();  

   Vector2 position;
};

#endif
