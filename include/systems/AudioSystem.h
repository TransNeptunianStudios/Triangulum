#ifndef AUDIOSYSTEM_H
#define AUDIOSYSTEM_H

#include "entityx/System.h"

#include "systems/Events.h"

class AudioManager;

class AudioSystem
      : public entityx::System<AudioSystem>
      , public entityx::Receiver<AudioSystem>
{
public:

   AudioSystem(AudioManager& audioManager);

   void configure(entityx::EventManager& eventManager);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

   void receive(const EvPlaySound& playSound);

private:

   AudioManager& m_audioManager;

};

#endif // AUDIOSYSTEM_H
