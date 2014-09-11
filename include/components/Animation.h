#ifndef ANIMATIONSTATE_H
#define ANIMATIONSTATE_H

#include "entityx/Entity.h"
#include "graphics/IAnimatible.h"

struct Animation : public entityx::Component<Animation>
{
   Animation(IAnimatible* _pAnimatible);

   IAnimatible* pAnimatible;
};

#endif // ANIMATIONSTATE_H
