#include <iostream>

#include "Zombie.hpp"
#include "color.hpp"

Zombie::Zombie()
{
	m_name = std::string();
	std::cout << "A zombie is summoned." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << YELLOW << m_name << RESET << " is terminated." << std::endl;
}

void Zombie::announce()
{
	std::cout << YELLOW << m_name << RESET << ": " << ZOMBIE_SOUND << std::endl;
}

void Zombie::setName(std::string name)
{
	m_name = name;	
	std::cout << "Certain zombie got a name : " << YELLOW << m_name << RESET << std::endl;
}
