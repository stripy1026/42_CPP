#ifndef _DOG_HPP_
#define _DOG_HPP_

#include "Animal.hpp"

class Dog : public Animal
{
  public:
    Dog();
    ~Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &rhs);
};

#endif //_DOG_HPP_
