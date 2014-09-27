#ifndef EVENTS_H
#define EVENTS_H

#include "entityx/Event.h"
#include "SoundId.h"

struct EvStartGame : public entityx::Event<EvStartGame>
{
   EvStartGame() {}
};

struct EvInit : public entityx::Event<EvInit>
{
   EvInit() {}
};

struct EvGameOver : public entityx::Event<EvGameOver>
{
   EvGameOver() {}
};

struct EvBossKilled : public entityx::Event<EvBossKilled>
{
   EvBossKilled() {}
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
