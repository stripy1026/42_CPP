#include <cstdlib>
#include <iostream>
#include <string>

int main()
{
    char input[] = "nan";

    std::cout << std::atoi(input) << std::endl;
    std::cout << std::strtof(input, NULL) << std::endl;
    std::cout << std::strtod(input, NULL) << std::endl;

    const char input2[] = "999999999999";
    double a = std::atoi(input2);
    std::cout << static_cast<double>(a) << std::endl;

    return (0);
}
