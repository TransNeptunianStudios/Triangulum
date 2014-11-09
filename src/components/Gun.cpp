#include "components/Gun.h"

Gun::Gun()
: direction()
, bulletType(BT_Simple)
, heat(0.0)
, cooldownTime(10000.0)
, shootTimer(0.0)
, isMainFirePressed(false)
{
}

Gun::Gun(const sf::Vector2f& _direction)
: direction(_direction)
, bulletType(BT_Simple)
, heat(0.0)
, cooldownTime(10000.0)
, shootTimer(0.0)
, isMainFirePressed(false)
{
}
