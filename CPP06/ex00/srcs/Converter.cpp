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

Converter::Converter(const std::string &input)
    : m_input(input), m_type("string"), m_char('0'), m_int(0), m_float(0), m_double(0), m_can_char(true),
      m_can_int(true)
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
    if (m_input.length() == 0)
        return;
    if (m_input == "nan")
    {
        m_type = "double";
        m_can_char = false;
        m_can_int = false;
        return;
    }
    if (m_input == "nanf")
    {
        m_type = "float";
        m_can_char = false;
        m_can_int = false;
        return;
    }
    if ((m_input.length() == 1) && (m_input[0] < '0' || m_input[0] > '9'))
    {
        m_type = "char";
        return;
    }
    unsigned int i = (m_input[0] == '-' || m_input[0] == '+') ? 1 : 0;
    while (('0' <= m_input[i] && m_input[i] <= '9') && (i < m_input.length()))
        ++i;
    if (i == m_input.length())
    {
        m_type = "int";
        return;
    }
    bool dot = false;
    if (m_input[i] == '.')
    {
        dot = true;
        ++i;
    }
    while (('0' <= m_input[i] && m_input[i] <= '9') && (i < m_input.length()))
        ++i;
    if (i == m_input.length())
    {
        m_type = "double";
        return;
    }
    if ((m_input[i] == 'f') && (dot) && (i + 1 == m_input.length()))
    {
        m_type = "float";
        return;
    }
}

void Converter::printChar(std::ostream &o) const
{
}

void Converter::printInt(std::ostream &o) const
{
}

void Converter::printFloat(std::ostream &o) const
{
}

void Converter::printDouble(std::ostream &o) const
{
}

std::ostream &operator<<(std::ostream &o, const Converter &converter)
{
    if (converter.getType() == "string")
        o << YELLOW << converter.getInput() << RESET " can't be converted to char, int, float, double." << std::endl;
    else
    {
        converter.printChar(o);
        converter.printInt(o);
        converter.printFloat(o);
        converter.printDouble(o);
    }
    return (o);
}
