#include <iomanip>
#include <iostream>

#include "Span.hpp"
#include "color.hpp"

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

std::vector<int> makeRandomPositiveVector(const unsigned int size, const unsigned int max_value)
{
    std::vector<int> vec;
    for (unsigned int i = 0; i < size; ++i)
        vec.push_back(rand() % max_value);
    return vec;
}

int main(void)
{
    {
        printTitle("Subject");
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << YELLOW "shortest span\t" RESET << sp.shortestSpan() << std::endl;
        std::cout << YELLOW "longest span \t" RESET << sp.longestSpan() << std::endl;
    }
    {
        printTitle("Exceptions");
        Span sp = Span(3);

        sp.addNumber(5);
        try
        {
            std::cout << YELLOW "shortest span\t" RESET << sp.shortestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "?\t";
            std::cerr << RED "Error : " RESET << e.what() << std::endl;
        }
        try
        {
            std::cout << YELLOW "longest span \t" RESET << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "?\t";
            std::cerr << RED "Error : " RESET << e.what() << std::endl;
        }
        try
        {
            sp.addNumber(6012);
            sp.addNumber(-791);
            sp.addNumber(832);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED "Error : " RESET << e.what() << std::endl;
        }
        std::cout << YELLOW "shortest span\t" RESET << sp.shortestSpan() << std::endl;
        std::cout << YELLOW "longest span \t" RESET << sp.longestSpan() << std::endl;
    }
    {
        printTitle("Lot of data");
        const unsigned int size = 100000;
        Span sp = Span(size);

        srand(time(NULL));
        std::vector<int> tmp = makeRandomPositiveVector(size, std::numeric_limits<int>::max());
        sp.fillUsingIterRange(tmp.begin(), tmp.end());
        std::cout << YELLOW "shortest span \t" RESET << sp.shortestSpan() << std::endl;
        std::cout << YELLOW "longest span  \t" RESET << sp.longestSpan() << std::endl;
    }
    return 0;
}
