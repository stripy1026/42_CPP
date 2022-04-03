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

#endif