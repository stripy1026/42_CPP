#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << YELLOW << "CALLED : " << RESET << "AMateria default constructor" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << YELLOW << "CALLED : " << RESET << "AMateria destructor" << std::endl;
}

AMateria::AMateria(const AMateria &src)
{
    std::cout << YELLOW << "CALLED : " << RESET << "AMateria copy constructor" << std::endl;
    *this = src;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
    if (this == &rhs)
        return (*this);
    m_type = rhs.m_type;
    return (*this);
}

AMateria::AMateria(const std::string &type) : m_type(type)
{
    std::cout << YELLOW << "CALLED : " << RESET << "AMateria constructor with type" << std::endl;
}

const std::string &AMateria::getType() const
{
    return (m_type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "*use " << GREEN << m_type << RESET << " at " << GREEN << target.getName() << RESET << "*"
              << std::endl;
}
