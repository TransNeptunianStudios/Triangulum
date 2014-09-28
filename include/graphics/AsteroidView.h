#ifndef ASTEROIDVIEW_H
#define ASTEROIDVIEW_H

#include "graphics/IDrawable.h"
#include "SpriteSheet.h"

class AsteroidView
        : public IDrawable
{
public:
    AsteroidView(SpriteSheet* pSpriteSheet);

    void draw(const Position& pos);

 private:

    SpriteSheet* m_pSpriteSheet;
};

#endif // ASTEROIDVIEW_H
