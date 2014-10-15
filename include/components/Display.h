#ifndef DISPLAY_H
#define DISPLAY_H

#include "entityx/Entity.h"
#include "SFML/Graphics/Rect.hpp"
#include "components/Animation.h"

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

   sf::IntRect coord;

   Blink blink;
};

#endif // DISPLAY_H
