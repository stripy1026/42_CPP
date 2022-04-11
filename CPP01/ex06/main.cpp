#include "Harl.hpp"

#define ERR_ARGNUM "Use 1 argument : DEBUG, INFO, WARNING, ERROR"
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define COMP_NINCASE "Probably complaining about insignificant problems"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << RED << "Error : " << RESET << ERR_ARGNUM << std::endl;
        return (EXIT_FAILURE);
    }
    Harl harl;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4 && levels[i] != argv[1])
        ++i;
    switch (i)
    {
    case 0:
        harl.complain(levels[0]);
    case 1:
        harl.complain(levels[1]);
    case 2:
        harl.complain(levels[2]);
    case 3:
        harl.complain(levels[3]);
        break;
    default:
        std::cout << "[ " << COMP_NINCASE << " ]" << std::endl;
    }
    return (EXIT_SUCCESS);
}