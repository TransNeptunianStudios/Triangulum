#ifndef EVENTS_H
#define EVENTS_H

#include "entityx/Event.h"
#include "SoundId.h"

struct PlaySound : public entityx::Event<PlaySound>
{
   PlaySound(SoundId _id)
   : id(_id)
   {
   }

   SoundId id;
};

#endif // EVENTS_H
