#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor has been called." << std::endl;
    m_brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Cat destructor has been called." << std::endl;
    delete m_brain;
}

Cat::Cat(const Cat &src) : Animal("Cat")
{
    std::cout << "Cat copy constrcutor has been called." << std::endl;
    m_brain = new Brain();
    *this = src;
}

Cat &Cat::operator=(const Cat &rhs)
{
    std::cout << "Cat copy assignment operator has been called." << std::endl;
    if (this == &rhs)
        return (*this);
    m_type = rhs.m_type;
    delete m_brain;
    m_brain = new Brain(*rhs.m_brain);
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << GREEN << "*Meow*" << RESET << std::endl;
}

void Cat::setIdeas(const int &i, const std::string &idea)
{
    m_brain->setIdeas(i, idea);
}

const std::string &Cat::getIdeas(const int &i) const
{
    return (m_brain->getIdeas(i));
}
