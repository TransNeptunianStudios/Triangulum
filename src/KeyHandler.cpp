#include "KeyHandler.h"

KeyHandler::KeyHandler()
: m_keyMap()
{
}

void KeyHandler::updateKey(SDL_Keycode key, bool isPressed)
{
   m_keyMap[key] = isPressed;
}

bool KeyHandler::isPressed(SDL_Keycode key) const
{
   KeyMap::const_iterator it = m_keyMap.find(key);

   if (it != m_keyMap.end())
   {
      return it->second;
   }

   return false;
}
