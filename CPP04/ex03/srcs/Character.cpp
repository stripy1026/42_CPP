#include "Character.hpp"

Character::Character()
{
    std::cout << YELLOW << "CALLED : " << RESET << "Character constructor" << std::endl;
}

Character::~Character()
{
    std::cout << YELLOW << "CALLED : " << RESET << "Character destructor" << std::endl;
    for (int i = 0; i < m_inventory_size; ++i)
    {
        if (m_inventory[i])
            delete m_inventory[i];
    }
}

Character::Character(const Character &src)
{
    std::cout << YELLOW << "CALLED : " << RESET << "Character copy constructor" << std::endl;
    *this = src;
}

Character &Character::operator=(const Character &rhs)
{
    if (this == &rhs)
        return (*this);
    m_name = rhs.m_name;
    for (int i = 0; i < m_inventory_size; ++i)
    {
        if (m_inventory[i])
            delete m_inventory[i];
        if (rhs.m_inventory[i])
            m_inventory[i] = rhs.m_inventory[i]->clone();
        else
            m_inventory[i] = NULL;
    }
    return (*this);
}

Character::Character(const std::string &name) : m_inventory(), m_name(name)
{
    std::cout << YELLOW << "CALLED : " << RESET << "Character constructor with name" << std::endl;
    // for (int i = 0; i < m_inventory_size; ++i)
    //     m_inventory[i] = NULL;
}

std::string const &Character::getName() const
{
    return (m_name);
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    int i = 0;
    while (i < m_inventory_size && m_inventory[i])
        ++i;
    if (i == m_inventory_size)
    {
        std::cout << GREEN << getName() << RESET << "'s inventory is full." << std::endl;
        delete m;
        return;
    }
    m_inventory[i] = m;
    std::cout << GREEN << getName() << RESET << " has equipped with " << GREEN << m_inventory[i]->getType() << RESET
              << " in slot " << i << std::endl;
}

void Character::unequip(int idx)
{
    if (0 <= idx && idx < m_inventory_size && m_inventory[idx])
    {
        std::cout << GREEN << getName() << RESET << " unequips " << GREEN << m_inventory[idx]->getType() << RESET
                  << " from slot " << idx << std::endl;
        m_inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (0 <= idx && idx < m_inventory_size && m_inventory[idx])
        m_inventory[idx]->use(target);
}
