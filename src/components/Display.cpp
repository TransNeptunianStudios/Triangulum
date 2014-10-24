#include "components/Display.h"

Blink::Blink()
: blinkingTime(0.0)
, timeSinceBlink(0.0)
, isOff(false)
{
}

void Blink::startBlink(double _blinkingTime)
{
   blinkingTime = _blinkingTime;
   timeSinceBlink = 0.0;
   isOff = false;
}

Display::Display()
: coord()
, blink()
{
}

Display::Display(const sf::IntRect& _coord)
: coord(_coord)
, color(sf::Color(255, 255, 255, 255))
, blink()
{
}

Display::Display(const sf::IntRect& _coord, sf::Color _color)
: coord(_coord)
, color(_color)
, blink()
{
}

