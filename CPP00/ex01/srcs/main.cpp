#include "PhoneBook.hpp"
#include "color.hpp"

#define ERR_WCOMMAND "Error : Use Valid command : ADD, SEARCH, EXIT"

int main(void)
{
    PhoneBook pb;
    std::string cmd;
    bool exit = false;

    pb.print_startup_message();
    while (!exit)
    {
        std::cout << GREEN << "Command : " << RESET;
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
            pb.add_contact();
        else if (cmd == "SEARCH")
            pb.display_contact();
        else if (cmd == "EXIT")
            exit = true;
        else
            std::cout << RED << ERR_WCOMMAND << RESET << std::endl;
    }
    return (0);
}
