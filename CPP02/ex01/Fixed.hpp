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
};

std::ostream &operator<<(std::ostream &os, const Fixed &rhs);

#endif // _FIXED_HPP_
