#ifndef AICONTROL_H
#define AICONTROL_H

#include "entityx/Entity.h"
#include "ai/IAi.h"

struct AiControl : public entityx::Component<AiControl>
{  
   AiControl(const IAiSP& _spAi);

   IAiSP spAi;
};

#endif // AICONTROL_H
