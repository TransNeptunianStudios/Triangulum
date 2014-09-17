#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include <memory>

class Position;

class IDrawable
{
public:

   virtual ~IDrawable() {}

   virtual void draw(const Position& pos) = 0;
};

typedef std::shared_ptr<IDrawable> IDrawableSP;

#endif // IDRAWABLE_H
