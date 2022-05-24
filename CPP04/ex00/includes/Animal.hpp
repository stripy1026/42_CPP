#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_

#include <iostream>

class Animal
{
  protected:
    std::string type;

  public:
    Animal();
    ~Animal();
    Animal(const Animal &src);
    Animal &operator=(const Animal &rhs);
};

#endif //_ANIMAL_HPP_
