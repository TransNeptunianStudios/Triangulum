#ifndef KEYHANDLER_H
#define KEYHANDLER_H

#include <map>
#include "SFML/Window/Keyboard.hpp"

class KeyHandler
{
public:

   KeyHandler();

   void updateKey(sf::Keyboard::Key key, bool isPressed);

   bool isPressed(sf::Keyboard::Key key) const;

private:

   typedef std::map<sf::Keyboard::Key, bool> KeyMap;
   KeyMap m_keyMap;
};

#endif
