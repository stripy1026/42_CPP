#include <cstdlib>
#include <iostream>

int main()
{
    char input[] = "nan";

    std::cout << std::atoi(input) << std::endl;
    std::cout << std::strtof(input, NULL) << std::endl;
    std::cout << std::strtod(input, NULL) << std::endl;

    const char input2[] = "4.2f";
    double a = std::strtod(input2, NULL);
    std::cout << static_cast<float>(a) << std::endl;

    return (0);
}
