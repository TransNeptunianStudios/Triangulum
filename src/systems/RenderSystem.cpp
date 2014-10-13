#include "SDL_opengl.h"
#include "systems/RenderSystem.h"
#include "components/Position.h"
#include "components/Display.h"
#include "components/Background.h"
#include "components/Menu.h"

using namespace entityx;

RenderSystem::RenderSystem(SpriteSheet* pSpriteSheet)
: m_pSpriteSheet(pSpriteSheet)
{
}

void RenderSystem::update(EntityManager &entities,
                          EventManager &events,
                          double dt)
{
   glClear(GL_COLOR_BUFFER_BIT);

   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();

   Position::Handle position;
   Background::Handle background;
   for (Entity entity : entities.entities_with_components(position, background))
   {
      glPushMatrix();

      glTranslatef(position->position.x,
                   position->position.y,
                   0.f);

      background->view.draw(position->position.y);

      glPopMatrix();
   }

   Display::Handle display;
   for (Entity entity : entities.entities_with_components(position, display))
   {      
      glPushMatrix();

      glTranslatef(position->position.x,
                   position->position.y,
                   0.f);

      glRotatef(position->heading,
                0.f, 0.f, 1.f);

      if (display->coord.x != 999 && display->coord.y != 999)
      {
         m_pSpriteSheet->draw(display->coord.x,
                              display->coord.y,
                              display->coord.optionalSize);
      }

      glPopMatrix();
   }

   Menu::Handle menu;
   for (Entity entity : entities.entities_with_components(position, menu))
   {
      glPushMatrix();

      glTranslatef(position->position.x,
                   position->position.y,
                   0.f);

      menu->spMenu->draw();

      glPopMatrix();
   }
}
