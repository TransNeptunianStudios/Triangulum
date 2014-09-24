#ifndef VOLUME_H
#define VOLUME_H

#include "entityx/Entity.h"
#include "utils/Vector2.h"

struct Box
{
   double w;
   double h;
   Vector2 offset;
};

struct Volume : public entityx::Component<Volume>
{
   Volume();

   typedef std::vector<Box> BoxList;

   BoxList m_boxes;
};

#endif // VOLUME_H
