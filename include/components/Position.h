#ifndef POSITION_H
#define POSITION_H

#include "entityx/Entity.h"
#include "SFML/System/Vector2.hpp"


struct Position : public entityx::Component<Position>
{
   Position();

   Position(const sf::Vector2f &_position);

   Position(const sf::Vector2f &_position, double _heading);

   sf::Vector2f position;

   double heading;
};

#endif
