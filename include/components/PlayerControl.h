#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H

#include "SDL_keycode.h"

#include "entityx/Entity.h"

struct PlayerControl : public entityx::Component<PlayerControl>
{
   PlayerControl();

   SDL_Keycode left;

   SDL_Keycode right;

   SDL_Keycode up;

   SDL_Keycode down;

   SDL_Keycode shoot;
};

#endif // PLAYERCONTROL_H
