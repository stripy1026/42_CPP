#include "Converter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED "Error : " RESET << "Use 1 argument." << std::endl;
        return (EXIT_FAILURE);
    }
    Converter c(argv[1]);
    std::cout << c.getInput() << " : " << c.getType() << std::endl;
    return (EXIT_SUCCESS);
}
