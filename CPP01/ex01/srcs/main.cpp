#include "Zombie.hpp"

int main()
{
	Zombie *horde;

	horde = zombieHorde(5, "Foo");
	for (int i = 0; i < 5; ++i)
		horde[i].announce();
	delete[] horde;
	return (0);
}
