#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "SDL.h"
#include "SDL_opengl.h"
#include "entityx/System.h"
#include "SpriteSheet.h"

class RenderSystem : public entityx::System<RenderSystem>
{
public:

   RenderSystem(SpriteSheet* pSpriteSheet);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   SpriteSheet* m_pSpriteSheet;
};

#endif // RENDERSYSTEM_H
