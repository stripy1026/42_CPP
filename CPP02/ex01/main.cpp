#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    a = Fixed(1234.4321f);

    std::cout << GREEN << "a is " << RESET << a << std::endl;
    std::cout << GREEN << "b is " << RESET << b << std::endl;
    std::cout << GREEN << "c is " << RESET << c << std::endl;
    std::cout << GREEN << "d is " << RESET << d << std::endl;

    std::cout << GREEN << "a is " << RESET << a.toInt() << YELLOW << " as integer" << RESET << std::endl;
    std::cout << GREEN << "b is " << RESET << b.toInt() << YELLOW << " as integer" << RESET << std::endl;
    std::cout << GREEN << "c is " << RESET << c.toInt() << YELLOW << " as integer" << RESET << std::endl;
    std::cout << GREEN << "d is " << RESET << d.toInt() << YELLOW << " as integer" << RESET << std::endl;

    std::cout << MAGENTA << "==========RAW BITS==========" << RESET << std::endl;
    std::cout << GREEN << "a bits " << RESET << a.getRawBits() << std::endl;
    std::cout << GREEN << "b bits " << RESET << b.getRawBits() << std::endl;
    std::cout << GREEN << "c bits " << RESET << c.getRawBits() << std::endl;
    std::cout << GREEN << "d bits " << RESET << d.getRawBits() << std::endl;
    std::cout << MAGENTA << "============================" << RESET << std::endl;

    return (0);
}
