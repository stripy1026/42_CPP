#include <iostream>

#include "HumanB.hpp"
#include "color.hpp"

HumanB::HumanB(std::string name) : m_name(name), m_weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void HumanB::setName(std::string name)
{
    m_name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
    m_weapon = &weapon;
}

void HumanB::attack() const
{
    if (m_weapon == NULL)
        std::cout << GREEN << m_name << RESET << " attacks with their " << YELLOW << "bare hands" << RESET << std::endl;
    else
    {
        std::cout << GREEN << m_name << RESET << " attacks with their " << YELLOW << m_weapon->getType() << RESET
                  << std::endl;
    }
}
