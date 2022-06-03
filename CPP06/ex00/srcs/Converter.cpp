#include "Converter.hpp"

Converter::Converter()
{
}

Converter::~Converter()
{
}

Converter::Converter(const Converter &src)
{
    static_cast<void>(src);
}

Converter &Converter::operator=(const Converter &rhs)
{
    static_cast<void>(rhs);
    return (*this);
}

Converter::Converter(const std::string &input) : m_input(input), m_type("string")
{
    m_detectType();
}

const std::string &Converter::getInput() const
{
    return (m_input);
}

const std::string &Converter::getType() const
{
    return (m_type);
}

void Converter::m_detectType()
{
    if (m_input == "nan")
    {
        m_type = "double";
        return;
    }
    if (m_input == "nanf")
    {
        m_type = "float";
        return;
    }
    if ((m_input.length() == 1) && (m_input[0] < '0' || m_input[0] > '9'))
    {
        m_type = "char";
        return;
    }
    int i = (m_input[0] == '-' || m_input[0] == '+') ? 1 : 0;
    while (('0' <= m_input[i] && m_input[i] <= '9') && (i < m_input.length()))
        ++i;
    if (i == m_input.length())
    {
        m_type = "int";
        return;
    }
    if (m_input[i] == '.')
        ++i;
    while (('0' <= m_input[i] && m_input[i] <= '9') && (i < m_input.length()))
        ++i;
    if (i == m_input.length())
    {
        m_type = "double";
        return;
    }
    if (m_input[i] == 'f' && (i + 1 == m_input.length()))
    {
        m_type = "float";
        return;
    }
}
