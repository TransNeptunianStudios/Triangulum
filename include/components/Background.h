#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "entityx/Entity.h"
#include "graphics/BackgroundView.h"

struct Background : public entityx::Component<Background>
{
   Background();

   BackgroundView view;
};

#endif // BACKGROUND_H
