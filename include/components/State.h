#ifndef STATE_H
#define STATE_H

#include "entityx/Entity.h"
#include "graphics/IAnimatible.h"

struct State : public entityx::Component<State>
{
   State(const IAnimatibleSP& _spAnimatible);

   IAnimatibleSP spAnimatible;
};

#endif // STATE_H
