#ifndef DISPLAY_H
#define DISPLAY_H

#include "entityx/Entity.h"
#include "graphics/IDrawable.h"

struct Display : public entityx::Component<Display>
{
   Display(IDrawable* _pDrawable);

   IDrawable* pDrawable;
};

#endif // DISPLAY_H
