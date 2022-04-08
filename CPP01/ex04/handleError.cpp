#include "handleError.hpp"

int handleError(std::string message, int value)
{
    std::cout << BRIGHT_RED << "Error : " << RESET << message << std::endl;
    return (value);
}
