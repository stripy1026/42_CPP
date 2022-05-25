#include "Animal.hpp"

Animal::Animal() : m_type("Animal")
{
    std::cout << "Animal constructor has been called." << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor has been called." << std::endl;
}

Animal::Animal(const Animal &src)
{
    (void)src;
}

Animal &Animal::operator=(const Animal &rhs)
{
    (void)rhs;
    return (*this);
}

Animal::Animal(const std::string type) : m_type(type)
{
    std::cout << "Animal constructor with type : " << YELLOW << type << RESET << " has been called." << std::endl;
}

const std::string &Animal::getType() const
{
    return (m_type);
}
