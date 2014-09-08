#include "graphics/SpaceShipView.h"

#include <SDL_opengl.h>

SpaceShipView::SpaceShipView()
{
}


void SpaceShipView::draw()
{
    // Draw spaceship
    glBegin(GL_TRIANGLES);
        glVertex3f( 0.0f, 0.1f, 0.0f);              // Top
        glVertex3f(-0.1f,-0.1f, 0.0f);              // Bottom Left
        glVertex3f( 0.1f,-0.1f, 0.0f);              // Bottom Right
    glEnd();
}
