#include "PhoneBook.hpp"

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
        exit = pb.get_command(cmd);
    }
    return (0);
}
