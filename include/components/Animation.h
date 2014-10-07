#ifndef ANIMATION_H
#define ANIMATION_H

#include "entityx/Entity.h"

struct SpriteSheetCoordinate
{
   SpriteSheetCoordinate()
   : x(0)
   , y(0)
   , extraSize(0)
   {
   }

   SpriteSheetCoordinate(unsigned _x, unsigned _y, int _extraSize = 0)
   : x(_x)
   , y(_y)
   , extraSize(_extraSize)
   {
   }

   unsigned x, y;

   int extraSize;
};

typedef std::vector<SpriteSheetCoordinate> CoordinateList;

enum AnimationType
{
   AT_RUN_ONCE,
   AT_LOOP
};

template<int tag>
struct Animation : public entityx::Component<Animation<tag>>
{
   Animation()
   : elapsedTime(0.0)
   , timePerFrame(0.0)
   , type(AT_RUN_ONCE)
   , coordList()
   , currentIndex(0)
   {
   }

   //SpriteSheetId spriteSheetId

   double elapsedTime;

   double timePerFrame;

   AnimationType type;

   CoordinateList coordList;

   size_t currentIndex;
};

typedef Animation<0> DeathAnimation;

#endif // ANIMATION_H
