#ifndef EVENTS_H
#define EVENTS_H

#include <SDL.h>
#include "entityx/Event.h"
#include "SoundId.h"

struct EvStartGame : public entityx::Event<EvStartGame>
{
   EvStartGame() {}
};

struct EvInit : public entityx::Event<EvInit>
{
   EvInit(int _levelNr)
   : levelNr(_levelNr)
   {
   }

   int levelNr;
};

struct EvPauseGame : public entityx::Event<EvPauseGame>
{
   EvPauseGame() {}
};

struct EvResumeGame : public entityx::Event<EvResumeGame>
{
   EvResumeGame() {}
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

struct EvKeyboard : public entityx::Event<EvKeyboard>
{
   EvKeyboard(SDL_Keycode _id, bool _isDown)
   : id(_id)
   , isDown(_isDown)
   {
   }

   SDL_Keycode id;
   bool isDown;
};

#endif // EVENTS_H
