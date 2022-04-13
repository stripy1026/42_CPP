#include "Fixed.hpp"

Fixed::Fixed() : m_raw_bits(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    m_raw_bits = rhs.m_raw_bits;
    return (*this);
}

Fixed::Fixed(const int num) : m_raw_bits(num << m_bnp_pos)
{
}

Fixed::Fixed(const float num) : m_raw_bits((int)roundf(num * (1 << m_bnp_pos)))
{
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

bool Fixed::operator>(const Fixed &rhs) const
{
    return (m_raw_bits > rhs.m_raw_bits);
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (m_raw_bits < rhs.m_raw_bits);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (m_raw_bits >= rhs.m_raw_bits);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (m_raw_bits <= rhs.m_raw_bits);
}

bool Fixed::operator==(const Fixed &rhs) const
{
    return (m_raw_bits == rhs.m_raw_bits);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (m_raw_bits != rhs.m_raw_bits);
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    Fixed ret;
    ret.m_raw_bits = m_raw_bits + rhs.m_raw_bits;
    return (ret);
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    Fixed ret;
    ret.m_raw_bits = m_raw_bits - rhs.m_raw_bits;
    return (ret);
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    const int i1 = m_raw_bits >> m_bnp_pos;
    const int i2 = rhs.m_raw_bits >> rhs.m_bnp_pos;
    const int f1 = m_raw_bits & ((1 << m_bnp_pos) - 1);
    const int f2 = rhs.m_raw_bits & ((1 << rhs.m_bnp_pos) - 1);
    Fixed ret;

    ret.m_raw_bits = ((i1 * i2) << m_bnp_pos) + ((f1 * f2) >> m_bnp_pos) + (i1 * f2) + (i2 * f1);
    return (ret);
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    const long div = (m_raw_bits >> m_bnp_pos) / rhs.m_raw_bits;
    Fixed ret;
    ret.m_raw_bits = (int)div;
    return (ret);
}

Fixed &Fixed::operator++()
{
    ++m_raw_bits;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;
    ++m_raw_bits;
    return (tmp);
}

Fixed &Fixed::operator--()
{
    --m_raw_bits;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    --m_raw_bits;
    return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a > b ? b : a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a > b ? b : a);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a < b ? b : a);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a < b ? b : a);
}

std::ostream &operator<<(std::ostream &os, const Fixed &rhs)
{
    os << rhs.toFloat();
    return (os);
}
