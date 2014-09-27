#include "components/Gun.h"

Gun::Gun()
: direction()
, isMainFirePressed(false)
, wasMainFirePressed(false)
{
}

Gun::Gun(const Vector2& _direction)
: direction(_direction)
, isMainFirePressed(false)
, wasMainFirePressed(false)
{
}
