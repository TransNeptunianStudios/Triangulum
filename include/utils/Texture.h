#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>
#include "SDL_opengl.h"

class Texture
{
public:

   Texture();

   bool load(const std::string& fileName);

   void draw();

   int width() const { return m_width; }

   int height() const { return m_height; }

   GLuint glTexture() const { return m_glTexture; }

private:

   GLuint m_glTexture;

   int m_width;

   int m_height;

   float m_halfLogoWidth;

   float m_halfLogoHeight;
};

#endif // TEXTURE_H
