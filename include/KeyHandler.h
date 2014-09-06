#ifndef KEYHANDLER_H
#define KEYHANDLER_H

#include <map>
#include "SDL_keycode.h"

class KeyHandler
{
public:

   KeyHandler();

   void updateKey(SDL_Keycode key, bool isPressed);

   bool isPressed(SDL_Keycode key) const;

private:

   typedef std::map<SDL_Keycode, bool> KeyMap;
   KeyMap m_keyMap;
};

#endif
