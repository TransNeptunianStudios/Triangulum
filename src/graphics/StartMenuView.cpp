#include "SDL_opengl.h"
#include "graphics/StartMenuView.h"
#include "components/Position.h"
#include "systems/Events.h"
#include "KeyHandler.h"

using namespace entityx;

StartMenuView::StartMenuView()
{
}

void StartMenuView::update(const KeyHandler& keyHandler,
                           EventManager& eventManager)
{
   if (keyHandler.isPressed(SDLK_SPACE))
   {
      eventManager.emit<EvStartGame>();
   }
}

void StartMenuView::draw(const Position &pos)
{
   glTranslatef(pos.position.x(),
                pos.position.y(),
                0.f);

   glBegin(GL_QUADS);
       glColor3f(1.0f, 0.0f, 0.0f);
       glVertex3f(-200.0f, -100.0f, 0.0f);               // Top Left
       glVertex3f(-200.0f, 100.0f, 0.0f);              // Bottom Left
       glVertex3f(200.0f, 100.0f, 0.0f);              // Bottom Right
       glVertex3f(200.0f, -100.0f, 0.0f);              // Top Right
   glEnd();

}
