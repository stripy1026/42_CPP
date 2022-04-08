#include "handleError.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
        return (handleError(ERR_ARGNUM, EXIT_FAILURE));
    std::cout << argv[0] << std::endl;
    return (EXIT_SUCCESS);
}