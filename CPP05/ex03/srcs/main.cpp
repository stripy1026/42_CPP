#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iomanip>

static void printTitle(std::string title)
{
    std::string toPrint;
    int size = 68;
    int n;

    toPrint = " " + title + " ";
    n = toPrint.size();
    if (n > size)
    {
        toPrint = toPrint.substr(0, size - 2);
        toPrint[size - 4] = '.';
        toPrint[size - 3] = ' ';
        n = toPrint.size();
    }
    std::cout << std::endl << std::setfill('=') << std::setw(size) << "" << std::endl;
    std::cout << std::setw(size / 2) << toPrint.substr(0, n / 2);
    std::cout << toPrint.substr(n / 2, n - n / 2);
    std::cout << std::setfill('=') << std::setw(size - size / 2 - n + n / 2) << "" << std::endl;
    std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
}

int main(void)
{
    srand(time(NULL));

    printTitle("Formular Creation");
    Bureaucrat pres("President", 1);
    Intern exploitedIntern;
    Form *forms[4];
    try
    {
        forms[0] = exploitedIntern.makeForm("shrubbery creation", "Target1");
    }
    catch (const std::exception &e)
    {
        std::cerr << RED "Error : " RESET << e.what() << std::endl;
    }
    try
    {
        forms[1] = exploitedIntern.makeForm("robotomy request", "Target2");
    }
    catch (const std::exception &e)
    {
        std::cerr << RED "Error : " RESET << e.what() << std::endl;
    }
    try
    {
        forms[2] = exploitedIntern.makeForm("presidential pardon", "Target3");
    }
    catch (const std::exception &e)
    {
        std::cerr << RED "Error : " RESET << e.what() << std::endl;
    }
    try
    {
        forms[3] = exploitedIntern.makeForm("formular", "Target4");
    }
    catch (const std::exception &e)
    {
        std::cerr << RED "Error : " RESET << e.what() << std::endl;
    }
    for (int i = 0; i < 3; i++)
    {
        if (forms[i])
        {
            std::cout << std::endl << *(forms[i]) << std::endl;
            pres.signForm(*(forms[i]));
            pres.executeForm(*(forms[i]));
        }
    }
    for (int i = 0; i < 3; i++)
        delete forms[i];
    return (0);
}
