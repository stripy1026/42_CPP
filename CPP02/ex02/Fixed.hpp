#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <cmath>
#include <iostream>

#include "color.hpp"

class Fixed
{
  private:
    int m_raw_bits;
    static const int m_bnp_pos = 8;

  public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &rhs);

    Fixed(const int num);
    Fixed(const float num);

    int getRawBits() const;
    void setRawBits(const int raw_bits);
    float toFloat() const;
    int toInt() const;

    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &rhs);

#endif // _FIXED_HPP_
