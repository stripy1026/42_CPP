#include <iostream>

#include "color.hpp"
#include "functions.hpp"

int main(void)
{
    {
        std::cout << YELLOW ">> subject" RESET << std::endl;

        int a = 2;
        int b = 3;

        ::swap(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
        std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

        std::string c = "chaine1";
        std::string d = "chaine2";

        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
        std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    }
    {
        std::cout << std::endl << YELLOW ">> strings" RESET << std::endl;

        std::string a = "Bat";
        std::string b = "Dove";
        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
        std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    }
    {
        std::cout << std::endl << YELLOW ">> char" RESET << std::endl;

        char a = 'a';
        char b = 'z';
        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
        std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    }
    {
        std::cout << std::endl << YELLOW ">> double" RESET << std::endl;

        double a = 3.4e21;
        double b = 3.3e21;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap(a, b);
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
        std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    }

    return (0);
}