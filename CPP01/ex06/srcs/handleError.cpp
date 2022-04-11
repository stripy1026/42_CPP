#include "handleError.hpp"

int handleError(std::string message, int value)
{
    std::cerr << BRIGHT_RED << "Error : " << RESET << message << std::endl;
    std::exit(value);
}
