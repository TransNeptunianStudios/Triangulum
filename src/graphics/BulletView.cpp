#include "SDL_opengl.h"
#include "graphics/BulletView.h"
#include "components/Position.h"

BulletView::BulletView()
{
}

void BulletView::draw(const Position& pos)
{
   glTranslatef(pos.position.x(),
                pos.position.y(),
                0.f);

   glBegin(GL_QUADS);
       glColor3f(0.0f, 1.0f, 0.0f);
       glVertex3f(-2.0f, -4.0f, 0.0f);               // Top Left
       glVertex3f(-2.0f, 4.0f, 0.0f);              // Bottom Left
       glVertex3f(2.0f, 4.0f, 0.0f);              // Bottom Right
       glVertex3f(2.0f, -4.0f, 0.0f);              // Top Right
   glEnd();
}
