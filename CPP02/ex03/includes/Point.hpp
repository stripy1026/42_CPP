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
};

Point::Point() : m_x(0), m_y(0)
{
}

Point::~Point()
{
}

Point::Point(const Point &src) : m_x(src.m_x), m_y(src.m_y)
{
}

Point &Point::operator=(const Point &rhs)
{
    m_x = rhs.m_x;
    m_y = rhs.m_y;
    return (*this);
}

#endif // _POINT_HPP_