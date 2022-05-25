#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << YELLOW << "CALLED : " << RESET << "Ice default constructor" << std::endl;
}

Ice::~Ice()
{
    std::cout << YELLOW << "CALLED : " << RESET << "Ice destructor" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria("ice")
{
    std::cout << YELLOW << "CALLED : " << RESET << "Ice copy constructor" << std::endl;
    *this = src;
}

Ice &Ice::operator=(const Ice &rhs)
{
    (void)rhs;
    return (*this);
}

AMateria *Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter &target)
{
    std::cout << "*shoots an ice bolt at " << GREEN << target.getName() << RESET << "*" << std::endl;
}
