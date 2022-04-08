#include "StringEditor.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
        handleError(ERR_ARGNUM, EXIT_FAILURE);
    StringEditor string_editor(argv[1]);
    string_editor.replace(argv[2], argv[3]);
    return (EXIT_SUCCESS);
}
