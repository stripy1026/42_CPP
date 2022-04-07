#include <iostream>

#include "Weapon.hpp"

int main()
{
	Weapon weapon;

	weapon.setType("Axe");
	std::cout << weapon.getType() << std::endl;

	return (0);
}