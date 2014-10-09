#include "SpriteSheet.h"
#include "SDL_image.h"

SpriteSheet::SpriteSheet(std::string filename, unsigned tileSize)
: m_filename(filename)
, m_tileSize(tileSize)
{
   SDL_Surface* pSurface = IMG_Load(m_filename.c_str());

    if (pSurface==NULL)
    {
        printf("Error: \"%s\"\n",SDL_GetError()); return;
    }

    m_rTS[0] = (double)tileSize / (double)pSurface->w;
    m_rTS[1] = (double)tileSize / (double)pSurface->h;

    glGenTextures(1,&m_texture);

    glBindTexture(GL_TEXTURE_2D, m_texture);

    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 pSurface->w,
                 pSurface->h,
                 0,
                 GL_RGBA,
                 GL_UNSIGNED_BYTE,
                 pSurface->pixels);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    //Unload SDL's copy of the data; we don't need it anymore because OpenGL now stores it in the texture.
    SDL_FreeSurface(pSurface);
}

bool SpriteSheet::draw(unsigned x, unsigned y, unsigned optionalSize) const
{
   unsigned tileSize = optionalSize != 0 ? optionalSize : m_tileSize;

   unsigned textureSize = tileSize / m_tileSize;

   float relPos = (float)tileSize / 2.0f;

   // chose to work with this spriteSheets texture.
   glBindTexture(GL_TEXTURE_2D,m_texture);

   // time to use textures!
   glEnable(GL_TEXTURE_2D);

   // Draw spaceship
   glBegin(GL_QUADS);

   glColor3f(1.0f, 1.0f, 1.0f);

   glTexCoord2f(x * m_rTS[0], (y+textureSize) * m_rTS[1]);
   glVertex3f( -relPos, relPos, 0.0f); // Lower Left

   glTexCoord2f((x+textureSize) * m_rTS[0], (y+textureSize) * m_rTS[1]);
   glVertex3f(relPos, relPos, 0.0f); // Lower Right

   glTexCoord2f((x+textureSize) * m_rTS[0], y * m_rTS[1]);
   glVertex3f(relPos, -relPos, 0.0f); // Upper Right

   glTexCoord2f(x * m_rTS[0], y * m_rTS[1]);
   glVertex3f(-relPos, -relPos, 0.0f); // Upper Left

   glEnd();

   glDisable(GL_TEXTURE_2D);

   return true;
}
