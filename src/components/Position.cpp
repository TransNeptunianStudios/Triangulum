
#include "components/Position.h"

Position::Position()
: position()
, heading(0.0)
{
}

Position::Position(const sf::Vector2f &_position)
: position(_position)
, heading(0.0)
{
}

Position::Position(const sf::Vector2f &_position, double _heading)
: position(_position)
, heading(_heading)
{
}
