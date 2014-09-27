#include "Animation.h"
#include "SpriteSheet.h"

//TBR
#include <iostream>

Animation::Animation(SpriteSheet *pSpriteSheet,
                     const vector<vector<int>> &spriteCoords,
                     int size,
                     float length,
                     AnimationStyle style)
    : m_pSpriteSheet(pSpriteSheet)
    , m_spriteCoords(spriteCoords)
    , m_size(size)
    , m_length(length)
    , m_style(style)
    , m_runTime(0.0)
{

}

void Animation::start()
{
    m_runTime = 0.0;
}

void Animation::update(const float dt)
{
    if(m_runTime < m_length)
        m_runTime += dt;
    else if(m_style == AS_LOOP)
        m_runTime = 0.0;
}

bool Animation::isFinished() const
{
    return m_runTime > m_length;
}

void Animation::draw() const
{
    float coordIndex = (m_runTime / m_length);
    coordIndex *= (float)m_spriteCoords.size();
    coordIndex = floor(fmod(coordIndex, 2));

    if(m_pSpriteSheet != nullptr)
        m_pSpriteSheet->draw(
                m_spriteCoords[coordIndex][0],
                m_spriteCoords[coordIndex][1]);
}
