#include <iostream>

#include "iter.hpp"

int main(void)
{
    int arrayInt[5] = {0, 1, 2, 3, 4};
    std::string arrayStr[5] = {"CPP", "Module", "07", "ex01", "test"};
    char arrayChar[7] = {'4', '2', 's', 'e', 'o', 'u', 'l'};

    iter<int>(arrayInt, 5, testFunction);
    std::cout << std::endl;
    iter<int>(arrayInt, 2, testFunction);
    std::cout << std::endl;

    iter<std::string>(arrayStr, 5, testFunction);
    std::cout << std::endl;

    iter<char>(arrayChar, 7, testFunction);
    std::cout << std::endl;

    return (0);
}
