#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	m_name = name;
	std::cout << YELLOW << m_name << RESET << " is summoned." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << YELLOW << m_name << RESET << " is terminated." << std::endl;
}

void Zombie::announce()
{
	std::cout << YELLOW << m_name << RESET << ": " << ZOMBIE_SOUND << std::endl;
}
