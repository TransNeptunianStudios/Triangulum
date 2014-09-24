#include "systems/CollisionSystem.h"

using namespace entityx;

CollisionSystem::CollisionSystem()
{
}

void CollisionSystem::update(EntityManager& entities,
                             EventManager& events,
                             double dt)
{
   Position::Handle pos1, pos2;
   Volume::Handle vol1, vol2;
   for (Entity first : entities.entities_with_components(pos1, vol1))
   {
      for (Entity second : entities.entities_with_components(pos2, vol2))
      {
         if (first != second)
         {
            if (checkCollision(pos1.get(),
                               vol1.get(),
                               pos2.get(),
                               vol2.get()))
            {
               first.destroy();
               second.destroy();
               return;
            }
         }
      }
   }
}

bool CollisionSystem::checkCollision(Position* pos1,
                                     Volume* vol1,
                                     Position* pos2,
                                     Volume* vol2)
{
   for (auto box1 : vol1->m_boxes)
   {
      Vector2 box1Pos(pos1->position.x() + box1.offset.x(),
                      pos1->position.y() + box1.offset.y());

      for (auto box2 : vol2->m_boxes)
      {
         Vector2 box2Pos(pos2->position.x() + box2.offset.x(),
                         pos2->position.y() + box2.offset.y());

         SDL_Rect one(convertToSDLRect(box1Pos, box1.w, box1.h));
         SDL_Rect two(convertToSDLRect(box2Pos, box2.w, box2.h));



         SDL_bool result = SDL_HasIntersection(&one, &two);

         return result == SDL_TRUE;
      }
   }

   return false;
}

SDL_Rect CollisionSystem::convertToSDLRect(const Vector2 &boxPos,
                                           double boxW,
                                           double boxH)
{
   SDL_Rect rect;
   rect.w = static_cast<int>(boxW * 800.0);
   rect.h = static_cast<int>(boxH * 600.0);
   rect.x = static_cast<int>(boxPos.x() * 400.0 + 400.0)-rect.w/2;
   rect.y = static_cast<int>(boxPos.y() * 300.0 + 300.0)-rect.h/2;

   return rect;
}
