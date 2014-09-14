#ifndef ANIMATIONSTATE_H
#define ANIMATIONSTATE_H

#include "entityx/Entity.h"
#include "graphics/IAnimatible.h"

struct Animation : public entityx::Component<Animation>
{
   Animation(const IAnimatibleSP& _spAnimatible);

   IAnimatibleSP spAnimatible;
};

#endif // ANIMATIONSTATE_H
