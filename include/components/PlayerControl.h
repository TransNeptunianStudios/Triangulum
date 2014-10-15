#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H

#include "SFML/Window/Keyboard.hpp"
#include "entityx/Entity.h"

struct PlayerControl : public entityx::Component<PlayerControl>
{
   PlayerControl();

   sf::Keyboard::Key left;

   sf::Keyboard::Key right;

   sf::Keyboard::Key up;

   sf::Keyboard::Key down;

   sf::Keyboard::Key shoot;

   sf::Keyboard::Key pause;
};

#endif // PLAYERCONTROL_H
