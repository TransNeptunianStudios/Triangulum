#ifndef EVENTS_H
#define EVENTS_H

#include "entityx/Event.h"
#include "SoundId.h"

struct EvInit : public entityx::Event<EvInit>
{
   EvInit() {}
};

struct EvPlaySound : public entityx::Event<EvPlaySound>
{
   EvPlaySound(SoundId _id)
   : id(_id)
   {
   }

   SoundId id;
};

#endif // EVENTS_H
