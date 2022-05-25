#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << YELLOW << "CALLED : " << RESET << "Cure default constructor" << std::endl;
}

Cure::~Cure()
{
    std::cout << YELLOW << "CALLED : " << RESET << "Cure destructor" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria("cure")
{
    std::cout << YELLOW << "CALLED : " << RESET << "Cure copy constructor" << std::endl;
    *this = src;
}

Cure &Cure::operator=(const Cure &rhs)
{
    (void)rhs;
    return (*this);
}

AMateria *Cure::clone() const
{
    return (new Cure());
}

void Cure::use(ICharacter &target)
{
    std::cout << "*heals " << GREEN << target.getName() << RESET << "'s wounds*" << std::endl;
}
