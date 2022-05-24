#ifndef _CAT_HPP_
#define _CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal
{
  private:
    Cat(const Cat &src);
    Cat &operator=(const Cat &rhs);

  public:
    Cat();
    ~Cat();
	
    void makeSound() const;
};

#endif //_CAT_HPP_
