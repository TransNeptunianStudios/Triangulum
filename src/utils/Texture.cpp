#include "SDL.h"
#include "SDL_image.h"
#include "utils/Texture.h"

Texture::Texture()
: m_glTexture()
, m_width(0)
, m_height(0)
{
}

bool Texture::load(const std::string& fileName)
{
   SDL_Surface* pSurface = IMG_Load(fileName.c_str());

    if (pSurface==NULL)
    {
        printf("Error: \"%s\"\n", SDL_GetError());
        return false;
    }

    m_width = pSurface->w;
    m_height = pSurface->h;

    glGenTextures(1, &m_glTexture);

    glBindTexture(GL_TEXTURE_2D, m_glTexture);

    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 m_width,
                 m_height,
                 0,
#ifdef __APPLE__
                 GL_BGRA,
#else
                 GL_RGBA,
#endif
                 GL_UNSIGNED_BYTE,
                 pSurface->pixels);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    //Unload SDL's copy of the data; we don't need it anymore because OpenGL now stores it in the texture.
    SDL_FreeSurface(pSurface);

    return true;
}
