#include "Bureaucrat.hpp"
#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << RED "Error: " RESET << e.what() << std::endl;
    }

    std::cout << " " << std::endl;

    Bureaucrat bob("Bob", 150);

    std::cout << "bob: " << bob << std::endl;
    std::cout << " " << std::endl;

    try
    {
        while (1)
        {
            bob.incrementGrade(50);
            std::cout << bob << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << RED "Error: " RESET << bob << " " << e.what() << std::endl;
    }

    std::cout << " " << std::endl;

    try
    {
        while (1)
        {
            bob.decrementGrade(50);
            std::cout << bob << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << RED "Error: " RESET << bob << " " << e.what() << std::endl;
    }

    std::cout << " " << std::endl;

    Bureaucrat ann = bob;
    Bureaucrat tom(ann);

    std::cout << "ann: " << ann << std::endl;
    std::cout << "tom: " << tom << std::endl;

    std::cout << " " << std::endl;

    Bureaucrat joe("Joe", 30);
    ann = joe;

    std::cout << "ann: " << ann << std::endl;
    std::cout << "joe: " << joe << std::endl;

    return 0;
}
