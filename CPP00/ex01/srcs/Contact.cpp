#include "Contact.hpp"

const std::string Contact::m_fields_name[5] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};

Contact::Contact()
{
    for (int i = first_name; i < darkest_secret + 1; ++i)
        m_fields[i] = std::string();
}

Contact::~Contact()
{
}

void Contact::make_info()
{
    std::cout << "Enter contact informations" << std::endl;
    for (int i = first_name; i < darkest_secret + 1; ++i)
    {
        std::cout << m_fields_name[i] << " : ";
        std::getline(std::cin, m_fields[i]);
    }
}

void Contact::show_status()
{

    for (int i = first_name; i < nickname + 1; ++i)
        std::cout << m_fields[i] << "\t";
    std::cout << std::endl;
}
