#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor has been called." << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor has been called." << std::endl;
}

Cat::Cat(const Cat &src) : Animal("Cat")
{
    (void)src;
}

Cat &Cat::operator=(const Cat &rhs)
{
    (void)rhs;
    return (*this);
}

const std::string &Cat::getType() const
{
    return (m_type);
}

void Cat::makeSound() const
{
    std::cout << GREEN << "*Meow*" << RESET << std::endl;
}
