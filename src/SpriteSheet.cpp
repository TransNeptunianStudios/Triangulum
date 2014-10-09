#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(const std::string& fileName, unsigned tileSize)
: m_tileSize(tileSize)
, m_texture()
{
   m_texture.load(fileName);

   m_rTS[0] = (double)tileSize / (double)m_texture.width();

   m_rTS[1] = (double)tileSize / (double)m_texture.height();
}

bool SpriteSheet::draw(unsigned x, unsigned y, unsigned optionalSize) const
{
   unsigned tileSize = optionalSize != 0 ? optionalSize : m_tileSize;

   unsigned textureSize = tileSize / m_tileSize;

   float relPos = (float)tileSize / 2.0f;

   // chose to work with this spriteSheets texture.
   glBindTexture(GL_TEXTURE_2D, m_texture.glTexture());

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
