#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string type) : m_type(type)
{
}

WrongAnimal::~WrongAnimal()
{
}

void WrongAnimal::makeSound() const
{
    std::cout << GREEN << "*Random animal sounds...*" << RESET << std::endl;
}
