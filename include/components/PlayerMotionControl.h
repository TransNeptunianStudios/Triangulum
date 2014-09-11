#ifndef PLAYERMOTIONCONTROL_H
#define PLAYERMOTIONCONTROL_H

#include "SDL_keycode.h"

#include "entityx/Entity.h"

// TODO: Change name to PlayerControl
struct PlayerMotionControl : public entityx::Component<PlayerMotionControl>
{
   PlayerMotionControl();

   SDL_Keycode left;

   SDL_Keycode right;

   SDL_Keycode up;

   SDL_Keycode down;

   SDL_Keycode shoot;
};

#endif // PLAYERMOTIONCONTROL_H
