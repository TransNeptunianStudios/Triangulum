#include "components/PlayerControl.h"

PlayerControl::PlayerControl()
: left(sf::Keyboard::A)
, right(sf::Keyboard::D)
, up(sf::Keyboard::W)
, down(sf::Keyboard::S)
, shoot(sf::Keyboard::Space)
, pause(sf::Keyboard::Escape)
{
}
