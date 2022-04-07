#include <iostream>

#include "HumanA.hpp"
#include "color.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : m_name(name), m_weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::setName(std::string name)
{
    m_name = name;
}

void HumanA::setWeapon(Weapon &weapon)
{
    m_weapon = weapon;
}

void HumanA::attack() const
{
    std::cout << GREEN << m_name << RESET << " attacks with their " << YELLOW << m_weapon.getType() << RESET
              << std::endl;
}
