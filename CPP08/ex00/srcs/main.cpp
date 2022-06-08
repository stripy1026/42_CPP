#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

#include "color.hpp"
#include "easyfind.hpp"

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
}

int main()
{
    // vector test
    printTitle("Int vector test");
    srand(time(NULL));
    {
        std::vector<int> intvec(5);
        std::cout << GREEN "Container values : " RESET << "[ ";
        for (std::vector<int>::iterator it = intvec.begin(); it != intvec.end(); ++it)
        {
            *it = rand() % 10;
            std::cout << *it << " ";
        }
        std::cout << "]" << std::endl;

        const int random = rand() % 10;
        std::cout << YELLOW "Find value : " RESET << random << std::endl;
        std::vector<int>::const_iterator res = easyfind(intvec, random);
        if (res == intvec.end())
            std::cout << RED "Value not found." RESET << std::endl;
        else
            std::cout << GREEN << *res << RESET " is found in Cantainer." << std::endl;

        std::cout << std::endl;
    }
    {
        // list test
        printTitle("Int list test");
        std::list<int> intvec(5);
        std::cout << GREEN "Container values : " RESET << "[ ";
        for (std::list<int>::iterator it = intvec.begin(); it != intvec.end(); ++it)
        {
            *it = rand() % 10;
            std::cout << *it << " ";
        }
        std::cout << "]" << std::endl;

        const int random = rand() % 10;
        std::cout << YELLOW "Find value : " RESET << random << std::endl;
        std::list<int>::const_iterator res = easyfind(intvec, random);
        if (res == intvec.end())
            std::cout << RED "Value not found." RESET << std::endl;
        else
            std::cout << GREEN << *res << RESET " is found in Cantainer." << std::endl;

        std::cout << std::endl;
    }
    {
        // deque test
        printTitle("Int deque test");
        std::deque<int> intvec(5);
        std::cout << GREEN "Container values : " RESET << "[ ";
        for (std::deque<int>::iterator it = intvec.begin(); it != intvec.end(); ++it)
        {
            *it = rand() % 10;
            std::cout << *it << " ";
        }
        std::cout << "]" << std::endl;

        const int random = rand() % 10;
        std::cout << YELLOW "Find value : " RESET << random << std::endl;
        std::deque<int>::const_iterator res = easyfind(intvec, random);
        if (res == intvec.end())
            std::cout << RED "Value not found." RESET << std::endl;
        else
            std::cout << GREEN << *res << RESET " is found in Cantainer." << std::endl;

        std::cout << std::endl;
    }
    return 0;
}
