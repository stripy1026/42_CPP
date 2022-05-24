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

    const std::string &getType() const;
    void makeSound() const;
};

#endif //_CAT_HPP_
