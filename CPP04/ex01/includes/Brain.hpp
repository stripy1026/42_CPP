#ifndef _BRANE_HPP_
#define _BRANE_HPP_

#include <iostream>

class Brain
{
  private:
    std::string m_ideas[100];

  public:
    Brain();
    ~Brain();
    Brain(const Brain &src);
    Brain &operator=(const Brain &rhs);

    void setIdeas(const int &i, const std::string &idea);
    const std::string &getIdeas(const int &i) const;
};

#endif // _BRANE_HPP_
