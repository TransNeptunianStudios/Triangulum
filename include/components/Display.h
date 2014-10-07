#ifndef DISPLAY_H
#define DISPLAY_H

#include "entityx/Entity.h"
#include "components/Animation.h"

struct Display : public entityx::Component<Display>
{
   Display();

   Display(const SpriteSheetCoordinate& _coord);

   SpriteSheetCoordinate coord;
};

#endif // DISPLAY_H
