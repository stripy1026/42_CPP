#ifndef _CAT_HPP_
#define _CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal
{
  public:
    Cat();
    ~Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &rhs);
};

#endif //_CAT_HPP_
