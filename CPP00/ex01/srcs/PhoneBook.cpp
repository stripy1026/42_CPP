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

bool PhoneBook::get_command(std::string cmd)
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
    std::cout << "Index | First name | Last name | Nickname" << std::endl;
    for (int i = 0; (i < m_num) && (i < 8); ++i)
    {
        std::cout << i + 1 << '\t';
        m_contacts[i].show_status();
    }
}
