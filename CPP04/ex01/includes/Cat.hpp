#ifndef _CAT_HPP_
#define _CAT_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
  private:
    Brain *m_brain;

  public:
    Cat();
    ~Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &rhs);

    void makeSound() const;
	void setIdeas(const int &i, const std::string &idea);
	const std::string &getIdeas(const int &i) const;
};

#endif //_CAT_HPP_
