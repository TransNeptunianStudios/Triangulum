#include "graphics/SpaceShipView.h"

#include <SDL_opengl.h>

SpaceShipView::SpaceShipView()
{
}


void SpaceShipView::draw()
{
    // Draw spaceship
    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
       glColor3f(1.0f, 0.0f, 0.0f); // Red
       glVertex2f(-0.5f, -0.5f);    // x, y
       glVertex2f( 0.5f, -0.5f);
       glVertex2f( 0.5f,  0.5f);
       glVertex2f(-0.5f,  0.5f);
    glEnd();
}
