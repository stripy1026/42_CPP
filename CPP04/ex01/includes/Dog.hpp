#ifndef _DOG_HPP_
#define _DOG_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
    Brain *m_brain;

    Dog(const Dog &src);
    Dog &operator=(const Dog &rhs);

  public:
    Dog();
    ~Dog();

    const std::string &getType() const;
    void makeSound() const;
};

#endif //_DOG_HPP_
