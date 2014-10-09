#include "SDL_opengl.h"
#include "graphics/BackgroundView.h"
#include "components/Position.h"
#include "ScreenSize.h"

BackgroundView::BackgroundView()
: m_texture()
, m_ratio((double)ScreenSize::width()/(double)ScreenSize::height())
, m_textureOffset(0.0)
, m_textureHeightStart(1.0/3.0)
{
   m_texture.load("../images/bg.png");
}

void BackgroundView::draw(double offset)
{
   const float screenWidth = ScreenSize::width();

   const float screenHeight = ScreenSize::height();

   // chose to work with this spriteSheets texture.
   glBindTexture(GL_TEXTURE_2D, m_texture.glTexture());

   // time to use textures!
   glEnable(GL_TEXTURE_2D);

   glBegin(GL_QUADS);

   glColor3f(1.0f, 1.0f, 1.0f);

   glTexCoord2f(0.0f, m_textureHeightStart+offset);
   glVertex3f(0.0f, 0.0f, -0.5f);
   glTexCoord2f(1.0f, m_textureHeightStart+offset);
   glVertex3f(screenWidth, 0.0, -0.5f);
   glTexCoord2f(1.0f, offset);
   glVertex3f(screenWidth, screenHeight, -0.5f);
   glTexCoord2f(0.0f, offset);
   glVertex3f(0.0, screenHeight, -0.5f);

   glEnd();

   glDisable(GL_TEXTURE_2D);
}
