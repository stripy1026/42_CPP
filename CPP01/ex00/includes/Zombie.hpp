#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include <string>
#include <iostream>

#include "color.hpp"

#define	ZOMBIE_SOUND "BraiiiiiiinnnzzzZ..."

class Zombie
{
	private:
		std::string m_name;

	public:
		Zombie(std::string name);
		~Zombie();

		void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif