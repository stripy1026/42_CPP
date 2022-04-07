#include "Zombie.hpp"

Zombie::Zombie()
{
	m_name = std::string();
}

Zombie::Zombie(std::string name)
{
	m_name = name;
}

Zombie::~Zombie()
{
	if (this)
		delete this;
	std::cout << YELLOW << m_name << RESET << " has been destroyed." << std::endl;
}

void Zombie::announce()
{
	std::cout << YELLOW << m_name << RESET << ": " << ZOMBIE_SOUND << std::endl;
}
