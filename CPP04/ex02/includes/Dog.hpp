#ifndef _DOG_HPP_
#define _DOG_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
    Brain *m_brain;

  public:
    Dog();
    ~Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &rhs);

    void makeSound() const;
    void setIdeas(const int &i, const std::string &idea);
    const std::string &getIdeas(const int &i) const;
};

#endif //_DOG_HPP_
