#include "components/PlayerControl.h"

PlayerControl::PlayerControl()
: left(sf::Keyboard::A)
, altLeft(sf::Keyboard::Left)
, right(sf::Keyboard::D)
, altRight(sf::Keyboard::Right)
, up(sf::Keyboard::W)
, altUp(sf::Keyboard::Up)
, down(sf::Keyboard::S)
, altDown(sf::Keyboard::Down)
, shoot(sf::Keyboard::Space)
, pause(sf::Keyboard::Escape)
{
}
