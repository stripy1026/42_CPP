#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <iostream>
#include <string>

class Contact
{
  private:
    std::string m_fields[5];
    const static std::string m_fields_name[5];
    enum e_field
    {
        first_name = 0,
        last_name,
        nickname,
        phone_number,
        darkest_secret
    };

  public:
    Contact();
    virtual ~Contact();
    void show_status();
};

const std::string Contact::m_fields_name[5] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};

Contact::Contact()
{
    std::string command;

    std::cout << "Enter contact informations" << std::endl;
    for (int i = first_name; i < darkest_secret + 1; ++i)
    {
        std::cout << m_fields_name[i] << " : ";
        std::getline(std::cin, command);
        m_fields[i] = command;
    }
}

Contact::~Contact()
{
}

void Contact::show_status()
{
    for (int i = first_name; i < darkest_secret + 1; ++i)
        std::cout << m_fields[i] << std::endl;
}

#endif