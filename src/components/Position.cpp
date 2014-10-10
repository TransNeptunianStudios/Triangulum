
#include "components/Position.h"

Position::Position()
: position()
, heading(0.0)
{
}

Position::Position(const Vector2 &_position)
: position(_position)
, heading(0.0)
{
}

Position::Position(const Vector2 &_position, double _heading)
: position(_position)
, heading(_heading)
{
}
