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
    std::cout << "Brain copy constrcutor has been called." << std::endl;
    *this = src;
}

Brain &Brain::operator=(const Brain &rhs)
{
    std::cout << "Brain copy assignment operator has been called." << std::endl;
    if (this == &rhs)
        return (*this);
    for (int i = 0; i < 100; ++i)
        m_ideas[i] = rhs.m_ideas[i];
    return (*this);
}

void Brain::setIdeas(const int &i, const std::string &idea)
{
    m_ideas[i] = idea;
}

const std::string &Brain::getIdeas(const int &i) const
{
    return m_ideas[i];
}
