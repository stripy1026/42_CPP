#ifndef _PHONEBOOK_HPP_
#define _PHONEBOOK_HPP_

#include <cstdlib>
#include "Contact.hpp"

#define ERR_WCOMMAND "Error : Use valid command : ADD, SEARCH, EXIT"
#define ERR_WINDEX "Error : Index out of range"

class PhoneBook
{
  private:
    Contact m_contacts[8];
    int m_num;

  public:
    PhoneBook();
    virtual ~PhoneBook();

    void print_startup_message();
    bool get_command(const std::string &cmd);
    void add_contact();
    void display_contact();
};

#endif