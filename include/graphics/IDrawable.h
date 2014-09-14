#ifndef IDRAWABLE_H
#define IDRAWABLE_H

#include <memory>

class IDrawable
{
public:

   virtual ~IDrawable() {}

   virtual void draw() = 0;
};

typedef std::shared_ptr<IDrawable> IDrawableSP;

#endif // IDRAWABLE_H
