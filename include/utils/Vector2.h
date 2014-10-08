#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:

   Vector2();

   Vector2(float x, float y);

   float x() const { return m_x; }

   float y() const { return m_y; }

   float& x() { return m_x; }

   float& y() { return m_y; }

   void normalize();

private:

   float length() const;

   float m_x;

   float m_y;
};

#endif // VECTOR2_H
