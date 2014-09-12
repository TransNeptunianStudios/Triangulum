#include "graphics/SpaceShipView.h"

// This should be used to load other file formats with IMG_LOAD
//#include <SDL_image.h>

SpaceShipView::SpaceShipView()
: m_state(SSS_Idle)
, m_duration(0.0)
{

  // TBR
  SDL_Surface* surface = SDL_LoadBMP("../images/ship.bmp");
  if (surface==NULL) { //If it failed, say why and don't continue loading the texture
      printf("Error: \"%s\"\n",SDL_GetError()); return;
  }

  glGenTextures(1,&m_texture);

  glBindTexture(GL_TEXTURE_2D, m_texture);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w,surface->h, 0, GL_RGB,GL_UNSIGNED_BYTE,surface->pixels);

  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

  //Unload SDL's copy of the data; we don't need it anymore because OpenGL now stores it in the texture.
  SDL_FreeSurface(surface);
}

void SpaceShipView::animate(const Vector2 velocity, double dt)
{
   double step = 200.0;

   switch (m_state)
   {
   case SSS_Idle:
      if (velocity.x() > 0.1)
      {
         m_state = SSS_Right1;
         m_duration = 0.0;
      }
      break;
   case SSS_Right1:
      m_duration += dt;
      if (velocity.x() > 0.1 &&
          m_duration > step)
      {
         m_state = SSS_Right2;
         m_duration = 0.0;
      }
   case SSS_Right2:
      m_duration += dt;
      if (velocity.x() > 0.1 &&
          m_duration > step)
      {
         m_state = SSS_Right3;
         m_duration = 0.0;
      }
   case SSS_Right3:
      if (velocity.x() < 0.3)
      {
         m_state = SSS_Idle;
      }
   }
}

void SpaceShipView::draw()
{
  //Set our loaded texture as the current 2D texture (this isn't actually technically necessary since our
  //texture was never unselected from above, but this is most clear)
  glBindTexture(GL_TEXTURE_2D,m_texture);
  //Tell OpenGL that all subsequent drawing operations should try to use the current 2D texture
  glEnable(GL_TEXTURE_2D);

   GLfloat color[3];

   switch (m_state)
   {
   case SSS_Idle:
      color[0] = 1.0;
      color[1] = 1.0;
      color[2] = 1.0;
      break;
   case SSS_Right1:
      color[0] = 1.0;
      color[1] = 0.7;
      color[2] = 0.7;
      break;
   case SSS_Right2:
      color[0] = 1.0;
      color[1] = 0.3;
      color[2] = 0.3;
      break;
   case SSS_Right3:
      color[0] = 1.0;
      color[1] = 0.0;
      color[2] = 0.0;
      break;
   }

  // Draw spaceship
  glBegin(GL_QUADS);
    glTexCoord2f(0, 1);
    glVertex3f( -0.1f, -0.1f, 0.0f); // Lower Left
    glTexCoord2f(1, 1);
    glVertex3f(  0.1f, -0.1f, 0.0f); // Lower Right
    glTexCoord2f(1, 0);
    glVertex3f(  0.1f,  0.1f, 0.0f); // Upper Right
    glTexCoord2f(0, 0);
    glVertex3f( -0.1f,  0.1f, 0.0f); // Upper Left
  glEnd();

    glDisable(GL_TEXTURE_2D);
}
