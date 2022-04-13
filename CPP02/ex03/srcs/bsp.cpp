#include "Point.hpp"

Fixed calPartition(const Point &p, const Point &a, const Point &b)
{
	Fixed Px = p.getX();
	Fixed Py = p.getY();
	Fixed Ax = a.getX();
	Fixed Ay = a.getY();
	Fixed Bx = b.getX();
	Fixed By = b.getY();
	Fixed ret;

	ret = (Px - Bx) * (Ay - By) - (Py - By) * (Ax - Bx);
	return (ret);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed p1;
	Fixed p2;
	Fixed p3;

	p1 = calPartition(point, a, b);
	p2 = calPartition(point, b, c);
	p3 = calPartition(point, c, a);

	return ((p1 < 0 && p2 < 0 && p3 < 0) || (p1 > 0 && p2 > 0 && p3 > 0));
}
