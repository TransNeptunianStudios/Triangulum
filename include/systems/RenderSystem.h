#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "SDL.h"
#include "SDL_opengl.h"
#include "entityx/System.h"

class RenderSystem : public entityx::System<RenderSystem>
{
public:

   RenderSystem(SDL_Window* pWindow);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   SDL_Window* m_pWindow;
};

#endif // RENDERSYSTEM_H
