#ifndef _HARL_HPP_
#define _HARL_HPP_

#include <iostream>
#include <string>

#include "color.hpp"

class Harl
{
  private:
    void debug() const;
    void info() const;
    void warining() const;
    void error() const;
    void noLevel() const;

  public:
    Harl();
    ~Harl();

    void complain(std::string level) const;
};

#endif // _HARL_HPP_
