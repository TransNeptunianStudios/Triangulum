#include "KeyHandler.h"

KeyHandler::KeyHandler()
: m_keyMap()
{
}

void KeyHandler::updateKey(sf::Keyboard::Key key, bool isPressed)
{
   m_keyMap[key] = isPressed;
}

bool KeyHandler::isPressed(sf::Keyboard::Key key) const
{
   KeyMap::const_iterator it = m_keyMap.find(key);

   if (it != m_keyMap.end())
   {
      return it->second;
   }

   return false;
}
