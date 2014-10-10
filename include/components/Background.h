#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "entityx/Entity.h"
#include "graphics/BackgroundView.h"

struct Background : public entityx::Component<Background>
{
   Background();

   Background(const std::string& fileName);

   BackgroundView view;
};

#endif // BACKGROUND_H
