#ifndef _HARL_HPP_
#define _HARL_HPP_

#include <iostream>
#include <string>

#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define BRIGHT_BLACK "\x1b[30;1m"
#define BRIGHT_RED "\x1b[31;1m"
#define BRIGHT_GREEN "\x1b[32;1m"
#define BRIGHT_YELLOW "\x1b[33;1m"
#define BRIGHT_BLUE "\x1b[34;1m"
#define BRIGHT_MAGENTA "\x1b[35;1m"
#define BRIGHT_CYAN "\x1b[36;1m"
#define BRIGHT_WHITE "\x1b[37;1m"
#define RESET "\x1b[0m"

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
