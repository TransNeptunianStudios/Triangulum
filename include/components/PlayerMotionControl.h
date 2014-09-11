#ifndef PLAYERMOTIONCONTROL_H
#define PLAYERMOTIONCONTROL_H

#include "SDL_keycode.h"

#include "entityx/Entity.h"

struct PlayerMotionControl : public entityx::Component<PlayerMotionControl>
{
   PlayerMotionControl();

   SDL_Keycode left;

   SDL_Keycode right;
};

#endif // PLAYERMOTIONCONTROL_H
