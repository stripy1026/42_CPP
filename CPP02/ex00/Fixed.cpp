#include "Fixed.hpp"

Fixed::Fixed() : m_raw_bits(0)
{
    std::cout << "Default constructor " << GREEN << "called" << RESET << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor " << GREEN << "called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor " << GREEN << "called" << RESET << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator " << GREEN << "called" << RESET << std::endl;
    m_raw_bits = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function " << GREEN << "called" << RESET << std::endl;
    return (m_raw_bits);
}

void Fixed::setRawBits(const int raw_bits)
{
    std::cout << "setRawBits member function " << GREEN << "called" << RESET << std::endl;
    m_raw_bits = raw_bits;
}