#ifndef DISPLAY_H
#define DISPLAY_H

#include "entityx/Entity.h"
#include "SFML/Graphics/Rect.hpp"
#include "components/Animation.h"
#include "SFML/Graphics/Color.hpp"

struct Blink
{
   Blink();

   void startBlink(double _blinkingTime);

   double blinkingTime;

   double timeSinceBlink;

   bool isOff;
};

struct Display : public entityx::Component<Display>
{
   Display();

   Display(const sf::IntRect& _coord);

   Display(const sf::IntRect& _coord, sf::Color _color);

   sf::IntRect coord;

   sf::Color color;

   Blink blink;
};

#endif // DISPLAY_H
