#ifndef _FIXED_HPP_
#define _FIXED_HPP_

class Fixed
{
  private:
    int m_fixed_point_number;
    static const int number_of_fractional_bits;

  public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &rhs);
    Fixed &operator=(const Fixed &rhs);
}

#endif // _FIXED_HPP_