#ifndef _BRANE_HPP_
#define _BRANE_HPP_

#include <iostream>

class Brain
{
  private:
    std::string m_ideas[100];

    Brain(const Brain &src);
    Brain &operator=(const Brain &rhs);

  public:
    Brain();
    ~Brain();
};

#endif // _BRANE_HPP_
