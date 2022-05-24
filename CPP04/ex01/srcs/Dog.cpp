#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor has been called." << std::endl;
	m_brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog destructor has been called." << std::endl;
	delete m_brain;
}

Dog::Dog(const Dog &src) : Animal("Dog")
{
    (void)src;
}

Dog &Dog::operator=(const Dog &rhs)
{
    (void)rhs;
    return (*this);
}

const std::string &Dog::getType() const
{
    return (m_type);
}

void Dog::makeSound() const
{
    std::cout << GREEN << "*Bark*" << RESET << std::endl;
}
