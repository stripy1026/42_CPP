#ifndef _HARL_HPP_
#define _HARL_HPP_

#include "handleError.hpp"

class Harl
{
  private:
    void debug();
    void info();
    void warining();
    void error();

  public:
    Harl();
    ~Harl();

    void complain(std::string level);
};

#endif // _HARL_HPP_
