#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <iostream>

#include "color.hpp"

class Fixed
{
  private:
    int m_raw_bits;
    static const int m_bnp_pos;

  public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &rhs);

    int getRawBits() const;
    void setRawBits(const int raw_bits);
};

#endif // _FIXED_HPP_