#include <iostream>

#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.attack();
        club.setType("baseball club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");

        HumanB jim("jim");
        jim.attack();

        jim.setWeapon(club);
        jim.attack();
        club.setType("baseball club");
        jim.attack();
    }
	
    return (0);
}
