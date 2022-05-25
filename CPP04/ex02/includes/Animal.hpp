#ifndef _ANIMAL_HPP_
#define _ANIMAL_HPP_

#include "color.hpp"

#include <iostream>

class Animal
{
  private:
    Animal(const Animal &src);
    Animal &operator=(const Animal &rhs);

  protected:
    std::string m_type;

  public:
    Animal();
    virtual ~Animal();

    Animal(const std::string type);
    const std::string &getType() const;
    virtual void makeSound() const = 0;
};

#endif //_ANIMAL_HPP_
