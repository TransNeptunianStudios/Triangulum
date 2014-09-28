#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <string>
#include <SDL.h>
#include <SDL_opengl.h>


class SpriteSheet
{
public:
    SpriteSheet(std::string filename, unsigned tileSize);

    bool draw(unsigned x, unsigned y, int extraSized = 0) const;

private:

    const unsigned m_tileSize;
    double m_rTS[2]; // Relative tile size (0-1 of whole sheit:)
    const std::string m_filename;
    GLuint m_texture;
};

#endif // SPRITESHEET_H
