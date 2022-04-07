#include "Zombie.hpp"

int main()
{
    Zombie *zombie;
    zombie = newZombie(std::string("Foo"));
    randomChump(std::string("Bar"));
    zombie->announce();
	delete zombie;
    return (0);
}