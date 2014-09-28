#ifndef ASTEROIDBOSSVIEW_H
#define ASTEROIDBOSSVIEW_H

#include "graphics/IDrawable.h"
#include "SpriteSheet.h"

class AsteroidBossView
        : public IDrawable
{
public:
    AsteroidBossView(SpriteSheet* pSpriteSheet);

    void draw(const Position& pos);

 private:

    SpriteSheet* m_pSpriteSheet;
};

#endif // ASTEROIDBOSSVIEW_H
