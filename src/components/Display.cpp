#include "components/Display.h"
#include "graphics/IDrawable.h"

Display::Display(IDrawable* pDrawable)
: m_pDrawable(pDrawable)
{
}

void Display::draw()
{
   m_pDrawable->draw();
}
