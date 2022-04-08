#include "StringEditor.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
        handleError(ERR_ARGNUM, EXIT_FAILURE);
    StringEditor string_editor(argv[1]);
    return (EXIT_SUCCESS);
}
