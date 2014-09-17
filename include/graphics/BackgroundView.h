#ifndef BACKGROUNDVIEW_H
#define BACKGROUNDVIEW_H

#include "graphics/IDrawable.h"

class BackgroundView : public IDrawable
{
public:

   BackgroundView();

   void draw(const Position& pos);

   GLuint m_texture;

   // TBR
   double m_ratio;

   double m_textureOffset;

   double m_textureHeightStart;

};

#endif // BACKGROUNDVIEW_H
