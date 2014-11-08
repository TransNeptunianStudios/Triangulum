#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H

#include "SFML/Window/Keyboard.hpp"
#include "entityx/Entity.h"

struct PlayerControl : public entityx::Component<PlayerControl>
{
   PlayerControl();

   sf::Keyboard::Key left, altLeft;

   sf::Keyboard::Key right, altRight;

   sf::Keyboard::Key up, altUp;

   sf::Keyboard::Key down, altDown;

   sf::Keyboard::Key shoot;

   sf::Keyboard::Key pause;
};

#endif // PLAYERCONTROL_H
