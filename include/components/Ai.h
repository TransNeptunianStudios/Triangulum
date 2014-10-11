#ifndef AI_H
#define AI_H

#include "entityx/Entity.h"
#include "ai/IAi.h"

struct Ai : public entityx::Component<Ai>
{  
   Ai();

   Ai(AiId _aiId);

   AiId aiId;
};

#endif // AI_H
