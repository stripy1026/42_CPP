#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return (0);
}
