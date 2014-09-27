#ifndef AICONTROLSYSTEM_H
#define AICONTROLSYSTEM_H

#include "entityx/System.h"
#include "systems/AiControlSystem.h"

class AiControlSystem : public entityx::System<AiControlSystem>
{
public:

   AiControlSystem();

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);


};

#endif // AICONTROLSYSTEM_H
