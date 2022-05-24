#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "It now has a brian !" << std::endl;
}

Brain::~Brain()
{
    std::cout << "It's brain has been blown up." << std::endl;
}

Brain::Brain(const Brain &src)
{
    (void)src;
}

Brain &Brain::operator=(const Brain &rhs)
{
    (void)rhs;
    return (*this);
}
