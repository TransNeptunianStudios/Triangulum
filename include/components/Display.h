#ifndef DISPLAY_H
#define DISPLAY_H

#include "components/Component.h"

class IDrawable;

class Display : public Component
{
public:

   Display(IDrawable* pDrawable);

   void draw();

private:

   IDrawable* m_pDrawable;

};

#endif // DISPLAY_H
