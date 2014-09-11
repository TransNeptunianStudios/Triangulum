#include "SDL_opengl.h"
#include "graphics/BulletView.h"

BulletView::BulletView()
{
}

void BulletView::draw()
{
   glBegin(GL_TRIANGLES);
       glColor3f(0.0f, 1.0f, 0.0f);
       glVertex3f( 0.0f, 0.02f, 0.0f);              // Top
       glVertex3f(-0.02f,-0.02f, 0.0f);              // Bottom Left
       glVertex3f( 0.02f,-0.02f, 0.0f);              // Bottom Right
   glEnd();
}
