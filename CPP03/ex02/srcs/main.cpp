#include <iomanip>

#include "FragTrap.hpp"

#define SIZE 52

static void printTitle(std::string title, bool toUpper = true)
{
    static int first;
    std::string toPrint;
    unsigned int size = (SIZE > 10 ? SIZE : 10);
    char c = '=';
    unsigned int n;

    if (first > 0)
        std::cout << std::endl;
    else
        first++;

    toPrint = " " + title + " ";
    if (toUpper)
    {
        for (int i = 0; toPrint[i]; i++)
            toPrint[i] = toupper(toPrint[i]);
    }
    n = toPrint.size();
    if (n > size)
    {
        toPrint = toPrint.substr(0, size - 2);
        toPrint[size - 4] = '.';
        toPrint[size - 3] = ' ';
        n = toPrint.size();
    }
    std::cout << std::setfill(c) << std::setw(size) << "" << std::endl;
    std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
    std::cout << toPrint.substr(n / 2, n - n / 2);
    std::cout << std::setfill(c) << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
    std::cout << std::setfill(c) << std::setw(size) << "" << std::endl;
    std::cout << std::setfill(' ');
}

int main(void)
{
    {
        printTitle("testing member functions");
        ClapTrap clapTrap("Clappy");
        FragTrap fragTrap("Fraggy");

        fragTrap.attack("random human");
        clapTrap.attack("random human");
        fragTrap.highFiveGuys();
        fragTrap.takeDamage(30);
        fragTrap.beRepaired(10);
        fragTrap.takeDamage(50);
        fragTrap.takeDamage(30);
        fragTrap.takeDamage(10);
        fragTrap.beRepaired(1);
        fragTrap.attack("Clappy");
    }
    {
        printTitle("running out of energy");
        FragTrap fragTrap("Fraggy");

        for (int i = 0; i < 50; i++)
            fragTrap.attack("random human");
        fragTrap.beRepaired(10);
        fragTrap.attack("random human");
        fragTrap.takeDamage(100);
    }
    return (0);
}
