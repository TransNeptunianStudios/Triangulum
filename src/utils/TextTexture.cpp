#include "SDL_ttf.h"
#include "utils/TextTexture.h"

TextTexture::TextTexture()
: m_glTexture()
, m_width(0)
, m_height(0)
, m_leftX(0.0)
, m_rightX(0.0)
, m_topY(0.0)
, m_bottomY(0.0)
{
}

bool TextTexture::load(const std::string& text,
                       const std::string& font,
                       SDL_Color color,
                       int size)
{
   TTF_Font* pFont = TTF_OpenFont(font.c_str(), size);

   if (pFont == nullptr)
   {
       printf("Error: \"%s\"\n", SDL_GetError());
       return false;
   }

   SDL_Surface* pFontSurface = TTF_RenderText_Blended(pFont,
                                                      text.c_str(),
                                                      color);

    if (pFontSurface == nullptr)
    {
        printf("Error: \"%s\"\n", SDL_GetError());
        return false;
    }

    m_width = pFontSurface->w;
    m_height = pFontSurface->h;

    setTextAlignment(TA_Left);

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
                 pFontSurface->pixels);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    TTF_CloseFont(pFont);

    //Unload SDL's copy of the data; we don't need it anymore because OpenGL now stores it in the texture.
    SDL_FreeSurface(pFontSurface);

    return true;
}

void TextTexture::setTextAlignment(TextAlign ta)
{
   m_topY = -m_height/2.0;
   m_bottomY = m_height/2.0;

   switch (ta)
   {
   case TA_Left:
      m_leftX = 0.0;
      m_rightX = (float)m_width;
      break;
   case TA_Right:
      m_leftX = (float)-m_width;
      m_rightX = 0.0;
      break;
   case TA_Center:
      m_leftX = -m_width/2.0;
      m_rightX = m_width/2.0;
      break;
   default:
      break;
   }
}

void TextTexture::draw()
{
   glBindTexture(GL_TEXTURE_2D, m_glTexture);

   glEnable(GL_TEXTURE_2D);

   glBegin(GL_QUADS);

   glColor3f(1.0f, 1.0f, 1.0f);

   glTexCoord2f(0.0f, 1.0f);
   glVertex3f(m_leftX, m_bottomY, 0.0f);
   glTexCoord2f(1.0f, 1.0f);
   glVertex3f(m_rightX, m_bottomY, 0.0f);
   glTexCoord2f(1.0f, 0.0f);
   glVertex3f(m_rightX, m_topY, 0.0f);
   glTexCoord2f(0.0f, 0.0f);
   glVertex3f(m_leftX, m_topY, 0.0f);

   glEnd();

   glDisable(GL_TEXTURE_2D);
}
