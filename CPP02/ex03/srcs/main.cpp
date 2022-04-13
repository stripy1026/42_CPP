#include "Point.hpp"

int main()
{
    Point a(1, 2);
    Point b(1, 6);
    Point c(9, 2);
    Point p1(2.1f, 3.1f);
    Point p2(0, 3);
    Point p3(3, 2);
    Point p4(5, 4);
    Point p5(4, 4);

    std::cout << "a " << a << ", b " << b << ", c " << c << std::endl;
    std::cout << "p1 " << p1 << " is " << (bsp(a, b, c, p1) ? "inside" : "outside") << std::endl;
    std::cout << "p2 " << p2 << " is " << (bsp(a, b, c, p2) ? "inside" : "outside") << std::endl;
    std::cout << "p3 " << p3 << " is " << (bsp(a, b, c, p3) ? "inside" : "outside") << std::endl;
    std::cout << "p4 " << p4 << " is " << (bsp(a, b, c, p4) ? "inside" : "outside") << std::endl;
    std::cout << "p5 " << p5 << " is " << (bsp(a, b, c, p5) ? "inside" : "outside") << std::endl;

    return (0);
}
