#ifndef _POINT_HPP_
#define _POINT_HPP_

#include "Fixed.hpp"

class Point
{
  private:
    const Fixed m_x;
    const Fixed m_y;

  public:
    Point();
    ~Point();
    Point(const Point &src);
    Point &operator=(const Point &rhs);

    Point(const float x, const float y);
	Fixed getX() const;
	Fixed getY() const;
};

std::ostream &operator<<(std::ostream &os, const Point &rhs);

bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif // _POINT_HPP_
