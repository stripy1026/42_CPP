#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include <string>
#include <iostream>

#define	ZOMBIE_SOUND "BraiiiiiiinnnzzzZ..."

class Zombie
{
	private:
		std::string name;

	public:
		void announce(void);
		Zombie *newZombie(std::string name);
};

void Zombie::announce()
{
	std::cout << name << ": " << ZOMBIE_SOUND << std::endl;
}

Zombie *Zombie::newZombie(std::string name)
{
}

#endif