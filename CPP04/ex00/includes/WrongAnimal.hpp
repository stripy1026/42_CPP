#ifndef _WRONG_ANIMAL_HPP_
#define _WRONG_ANIMAL_HPP_

#include "color.hpp"

#include <iostream>

class WrongAnimal
{
  protected:
    std::string m_type;

  public:
    WrongAnimal(const std::string type);
    void makeSound() const;
};

#endif //_WRONG_ANIMAL_HPP_
