#ifndef DISPLAY_H
#define DISPLAY_H

#include "entityx/Entity.h"
#include "graphics/IDrawable.h"

struct Display : public entityx::Component<Display>
{
   Display(const IDrawableSP& _spDrawable);

   IDrawableSP spDrawable;
};

#endif // DISPLAY_H
