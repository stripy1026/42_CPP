#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "New Phonebook created." << std::endl;
    m_num = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::print_startup_message()
{
    std::cout << "Enter command : [ADD, SEARCH, EXIT]" << std::endl;
}

bool PhoneBook::get_command(const std::string &cmd)
{
    if (cmd == "ADD")
    {
        add_contact();
        return (false);
    }
    if (cmd == "SEARCH")
    {
        display_contact();
        return (false);
    }
    if (cmd == "EXIT")
        return (true);
    std::cout << RED << ERR_WCOMMAND << RESET << std::endl;
    return (false);
}

void PhoneBook::add_contact()
{
    m_contacts[m_num % 8].make_info();
    m_num++;
}

void PhoneBook::display_contact()
{
    std::cout << MAGENTA << "|     Index|First name| Last name|  Nickname|" << RESET << std::endl;
    for (int i = 0; (i < m_num) && (i < 8); ++i)
    {
        std::cout << '|';
        std::cout.width(10);
        std::cout << i + 1 << '|';
        m_contacts[i].show_status();
    }
    std::string idx;
    int num;
    std::cout << GREEN << "Index : " << RESET;
    std::getline(std::cin, idx);
    num = std::atoi(idx.c_str());
    if (num < 1 || num > m_num)
        std::cout << RED << ERR_WINDEX << RESET << std::endl;
    else
        m_contacts[num - 1].display();
}
