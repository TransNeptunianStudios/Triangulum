#ifndef SCREENSIZE_H
#define SCREENSIZE_H

class ScreenSize
{
public:

   static void setWidth(int _w)
   {
      w = _w;
   }

   static void setHeight(int _h)
   {
      h = _h;
   }

   static int width()
   {
      return w;
   }

   static int height()
   {
      return h;
   }

private:

   static int w;

   static int h;
};

#endif // SCREENSIZE_H
