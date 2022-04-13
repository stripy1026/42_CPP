#include "Fixed.hpp"

Fixed::Fixed() : m_raw_bits(0)
{
    std::cout << "Default constructor " << GREEN << "called" << RESET << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor " << GREEN << "called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &src) : m_raw_bits(src.m_raw_bits)
{
    std::cout << "Copy constructor " << GREEN << "called" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator " << GREEN << "called" << RESET << std::endl;
    m_raw_bits = rhs.m_raw_bits;
    return (*this);
}

Fixed::Fixed(const int num) : m_raw_bits(num << m_bnp_pos)
{
    std::cout << "Int constructor " << GREEN << "called" << RESET << std::endl;
}

Fixed::Fixed(const float num) : m_raw_bits((int)roundf(num * (1 << m_bnp_pos)))
{
    std::cout << "Float constructor " << GREEN << "called" << RESET << std::endl;
}

int Fixed::getRawBits() const
{
    return (m_raw_bits);
}

void Fixed::setRawBits(const int raw_bits)
{
    m_raw_bits = raw_bits;
}

float Fixed::toFloat() const
{
    return ((float)m_raw_bits / (1 << m_bnp_pos));
}

int Fixed::toInt() const
{
    return (m_raw_bits >> m_bnp_pos);
}

std::ostream &operator<<(std::ostream &os, const Fixed &rhs)
{
    os << rhs.toFloat();
    return (os);
}
