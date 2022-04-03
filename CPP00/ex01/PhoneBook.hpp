#ifndef _PHONEBOOK_HPP_
#define _PHONEBOOK_HPP_

#include "Contact.hpp"

class PhoneBook
{
  private:
    Contact m_contacts[8];
    int m_num;

  public:
    PhoneBook();
    virtual ~PhoneBook();

    void print_startup_message();
    void add_contact();
    void display_contact();
};

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

void PhoneBook::add_contact()
{
    m_contacts[m_num % 8].make_info();
    m_num++;
}

void PhoneBook::display_contact()
{
    std::cout << "Index | First name | Last name | Nickname" << std::endl;
    for (int i = 0; (i < m_num) && (i < 8); ++i)
        m_contacts[i].show_status();
}

#endif