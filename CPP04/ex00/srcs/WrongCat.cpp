#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat")
{
}

void WrongCat::makeSound() const
{
    std::cout << GREEN << "*Meow*" << RESET << std::endl;
}
