#include "Point.hpp"

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
    (void)rhs;
    return (*this);
}

Point::Point(const float x, const float y) : m_x(x), m_y(y)
{
}

Fixed Point::getX() const
{
    return (m_x);
}

Fixed Point::getY() const
{
    return (m_y);
}

std::ostream &operator<<(std::ostream &os, const Point &rhs)
{
	os << "(" << rhs.getX() << ", " << rhs.getY() << ")";
	return (os);
}
