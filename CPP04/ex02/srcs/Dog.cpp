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
    std::cout << "Dog copy constructor has been called." << std::endl;
    m_brain = new Brain();
    *this = src;
}

Dog &Dog::operator=(const Dog &rhs)
{
    std::cout << "Dog copy assignment operator has been called." << std::endl;
    if (this == &rhs)
        return (*this);
    m_type = rhs.m_type;
    delete m_brain;
    m_brain = new Brain(*rhs.m_brain);
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << GREEN << "*Bark*" << RESET << std::endl;
}

void Dog::setIdeas(const int &i, const std::string &idea)
{
    m_brain->setIdeas(i, idea);
}

const std::string &Dog::getIdeas(const int &i) const
{
    return (m_brain->getIdeas(i));
}
