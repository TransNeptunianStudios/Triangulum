#ifndef BACKGROUNDVIEW_H
#define BACKGROUNDVIEW_H

#include "utils/Texture.h"

class BackgroundView
{
public:

   BackgroundView(const std::string& fileName);

   void draw(double offset);

private:

   Texture m_texture;

   double m_ratio;

   double m_textureOffset;

   double m_textureHeightStart;

};

#endif // BACKGROUNDVIEW_H
