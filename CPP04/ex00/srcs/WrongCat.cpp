#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat")
{
}

WrongCat::~WrongCat()
{
}

void WrongCat::makeSound() const
{
    std::cout << GREEN << "*Meow*" << RESET << std::endl;
}
