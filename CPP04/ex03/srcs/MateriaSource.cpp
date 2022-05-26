#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : m_source_slot(0)
{
    std::cout << YELLOW << "CALLED : " << RESET << "MateriaSource constructor" << std::endl;
    for (int i = 0; i < m_source_size; ++i)
        m_sources[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    std::cout << YELLOW << "CALLED : " << RESET << "MateriaSource destructor" << std::endl;
    for (int i = 0; i < m_source_size; ++i)
    {
        if (m_sources[i])
            delete m_sources[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    std::cout << YELLOW << "CALLED : " << RESET << "MateriaSource copy constructor" << std::endl;
    *this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
    if (this == &rhs)
        return (*this);
    m_source_slot = rhs.m_source_slot;
    for (int i = 0; i < m_source_size; ++i)
    {
        if (m_sources[i])
            delete m_sources[i];
        if (rhs.m_sources[i])
            m_sources[i] = rhs.m_sources[i]->clone();
        else
            m_sources[i] = NULL;
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;
    if (m_source_slot == m_source_size)
    {
        std::cout << "This source is full." << std::endl;
        return;
    }
    m_sources[m_source_slot] = m;
    std::cout << "You can now learn " << m_sources[m_source_slot]->getType() << " from source slot " << m_source_slot
              << std::endl;
    ++m_source_slot;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    int i = 0;
    while (i < m_source_slot && m_sources[i]->getType() != type)
        ++i;
    if (i == m_source_slot)
    {
        std::cout << "This source doesn't have type : " << type << std::endl;
        return (NULL);
    }
    return (m_sources[i]->clone());
}
