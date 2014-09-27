#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>

using namespace std;

enum AnimationStyle
{
    AS_ONCE, AS_LOOP
};

class SpriteSheet;

class Animation
{
public:
    Animation(SpriteSheet* pSpriteSheet,
              const vector<vector<int>>& spriteCoords,
              int size,
              float length,
              AnimationStyle style);

    void start();

    void update(const float dt);

    bool isFinished() const;

    void draw() const;

private:
    SpriteSheet* m_pSpriteSheet;

    // TODO: should be a int
    const vector<vector<int>>  m_spriteCoords;
    const int m_size;
    const float m_length;
    const AnimationStyle m_style;

    float m_runTime;
};

#endif // ANIMATION_H
