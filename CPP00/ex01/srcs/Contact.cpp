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
    std::string out;
    std::string idx;

    for (int i = first_name; i < nickname + 1; ++i)
    {
        if (m_fields[i].size() > 10)
        {
            out = m_fields[i].substr(0, 9);
            out.push_back('.');
        }
        else
            out = m_fields[i];
        std::cout.width(10);
        std::cout << out << '|';
    }
    std::cout << std::endl;
}

void Contact::display()
{
    for (int i = first_name; i < darkest_secret + 1; ++i)
        std::cout << m_fields_name[i] << " : " << m_fields[i] << std::endl;
}