#include "components/Gun.h"

Gun::Gun()
: direction()
, bulletType(BT_Simple)
, isMainFirePressed(false)
, wasMainFirePressed(true)
{
}

Gun::Gun(const sf::Vector2f& _direction)
: direction(_direction)
, bulletType(BT_Simple)
, isMainFirePressed(false)
, wasMainFirePressed(true)
{
}
