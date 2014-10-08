#include "components/Gun.h"

Gun::Gun()
: direction()
, bulletType(BT_Simple)
, isMainFirePressed(false)
, wasMainFirePressed(true)
{
}

Gun::Gun(const Vector2& _direction)
: direction(_direction)
, bulletType(BT_Simple)
, isMainFirePressed(false)
, wasMainFirePressed(true)
{
}
