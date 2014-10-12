#ifndef TEXTTEXTURE_H
#define TEXTTEXTURE_H

#include <string>
#include "SDL.h"
#include "SDL_opengl.h"

enum TextAlign
{
   TA_Left,
   TA_Right,
   TA_Center,
};

class TextTexture
{
public:

   TextTexture();

   ~TextTexture();

   bool load(const std::string& text,
             const std::string& font,
             SDL_Color color,
             int size);

   void setTextAlignment(TextAlign ta);

   void draw();

private:

   GLuint m_glTexture;

   int m_width, m_height;

   float m_leftX, m_rightX;

   float m_topY, m_bottomY;
};

#endif // TEXTTEXTURE_H
