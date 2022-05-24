#ifndef _DOG_HPP_
#define _DOG_HPP_

#include "Animal.hpp"

class Dog : public Animal
{
  private:
    Dog(const Dog &src);
    Dog &operator=(const Dog &rhs);

  public:
    Dog();
    ~Dog();

    std::string getType() const;
	void makeSound() const;
};

#endif //_DOG_HPP_
