#ifndef BACKGROUNDVIEW_H
#define BACKGROUNDVIEW_H

#include "SDL_opengl.h"

class BackgroundView
{
public:

   BackgroundView();

   void draw(double offset);

private:

   GLuint m_texture;

   // TBR
   double m_ratio;

   double m_textureOffset;

   double m_textureHeightStart;

};

#endif // BACKGROUNDVIEW_H
