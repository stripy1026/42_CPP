#include <iomanip>

#include "DiamondTrap.hpp"

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

    printTitle("Experiment for DiamondTrap has initiated.");
    DiamondTrap d("DI4M_TP");

    d.attack("everything promiscuously");
    d.guardGate();
    d.highFiveGuys();
    d.takeDamage(13);
    d.beRepaired(47);

    DiamondTrap dCopy(d);

    d.whoAmI();
    dCopy.whoAmI();

    return (0);
}
