#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <string>
#include "utils/Texture.h"

class SpriteSheet
{
public:
    SpriteSheet(const std::string& fileName, unsigned tileSize);

    bool draw(unsigned x, unsigned y, unsigned optionalSize = 0) const;

private:

    const unsigned m_tileSize;

    double m_rTS[2]; // Relative tile size (0-1 of whole sheit:)

    Texture m_texture;
};

#endif // SPRITESHEET_H
