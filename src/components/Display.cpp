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

Display::Display(const SpriteSheetCoordinate& _coord)
: coord(_coord)
, blink()
{
}
