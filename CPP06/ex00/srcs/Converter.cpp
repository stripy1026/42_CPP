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
      m_can_int(true), m_can_float(true), m_is_erange(false)
{
    m_detectType();
    const std::string names[4] = {"char", "int", "float", "double"};
    void (Converter::*convertOne[4])() = {&Converter::m_convertChar, &Converter::m_convertInt,
                                          &Converter::m_convertFloat, &Converter::m_convertDouble};
    int i = 0;
    while (i < 4 && m_type != names[i])
        ++i;
    if (i < 4)
        (this->*convertOne[i])();
}

const std::string &Converter::getInput() const
{
    return (m_input);
}

const std::string &Converter::getType() const
{
    return (m_type);
}

const bool &Converter::getIsErange() const
{
    return (m_is_erange);
}

void Converter::m_detectType()
{
    if (m_input.length() == 0)
        return;
    if (m_input == "nan" || m_input == "-inf" || m_input == "inf" || m_input == "+inf")
    {
        m_type = "double";
        m_can_char = false;
        m_can_int = false;
        return;
    }
    if (m_input == "nanf" || m_input == "-inff" || m_input == "inff" || m_input == "+inff")
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
    bool numeric = false;
    while (('0' <= m_input[i] && m_input[i] <= '9') && (i < m_input.length()))
    {
        numeric = true;
        ++i;
    }
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
    {
        numeric = true;
        ++i;
    }
    if (i == m_input.length() && dot && numeric)
    {
        m_type = "double";
        return;
    }
    if ((m_input[i] == 'f') && dot && (i + 1 == m_input.length()) && numeric)
    {
        m_type = "float";
        return;
    }
}

void Converter::m_convertChar()
{
    m_char = m_input[0];
    m_int = static_cast<int>(m_char);
    m_float = static_cast<float>(m_char);
    m_double = static_cast<double>(m_char);
}

void Converter::m_convertInt()
{
    const char *value = m_input.c_str();
    if ((strlen(value) >= 10 && strcmp(value, "2147483647") > 0) ||
        (value[0] == '-' && strlen(value) >= 11 && strcmp(value + 1, "2147483648") > 0) ||
        (value[0] == '+' && strlen(value) >= 11 && strcmp(value + 1, "2147483647") > 0))
    {
        m_is_erange = true;
        return;
    }
    m_int = std::atoi(m_input.c_str());
    if (0 > m_int || m_int > 255)
        m_can_char = false;
    if (m_can_char)
        m_char = static_cast<char>(m_int);
    m_float = static_cast<float>(m_int);
    m_double = static_cast<double>(m_int);
}

void Converter::m_convertFloat()
{
    m_float = std::strtof(m_input.c_str(), NULL);
    if (errno == ERANGE)
    {
        m_is_erange = true;
        return;
    }
    if (0 > m_float || m_float > 255)
        m_can_char = false;
    if (m_can_char)
        m_char = static_cast<char>(m_float);
    if (m_float < std::numeric_limits<int>::min() || m_float > std::numeric_limits<int>::max())
        m_can_int = false;
    if (m_can_int)
        m_int = static_cast<int>(m_float);
    m_double = static_cast<double>(m_float);
}

void Converter::m_convertDouble()
{
    m_double = std::strtod(m_input.c_str(), NULL);
    if (errno == ERANGE)
    {
        m_is_erange = true;
        return;
    }
    if (0 > m_double || m_double > 255)
        m_can_char = false;
    if (m_can_char)
        m_char = static_cast<char>(m_double);
    if (m_double < std::numeric_limits<int>::min() || m_double > std::numeric_limits<int>::max())
        m_can_int = false;
    if (m_can_int)
        m_int = static_cast<int>(m_double);
    if (m_double < -std::numeric_limits<float>::max() || m_double > std::numeric_limits<float>::max())
    {
        m_can_float = false;
        return;
    }
    m_float = static_cast<float>(m_double);
}

void Converter::printChar(std::ostream &o) const
{
    o << GREEN "char: " RESET;
    if (!m_can_char)
    {
        o << "impossible" << std::endl;
        return;
    }
    if (m_char > 31 && m_char < 127)
        o << "'" << m_char << "'" << std::endl;
    else
        o << "non displayable" << std::endl;
}

void Converter::printInt(std::ostream &o) const
{
    o << GREEN "int: " RESET;
    if (!m_can_int)
    {
        o << "impossible" << std::endl;
        return;
    }
    o << m_int << std::endl;
}

void Converter::printFloat(std::ostream &o) const
{
    o << GREEN "float: " RESET;
    if (!m_can_float)
    {
        o << "impossible" << std::endl;
        return;
    }
    o.precision(1);
    o << std::fixed << m_float << 'f' << std::endl;
}

void Converter::printDouble(std::ostream &o) const
{
    o << GREEN "double: " RESET;
    o.precision(1);
    o << std::fixed << m_double << std::endl;
}

std::ostream &operator<<(std::ostream &o, const Converter &converter)
{
    if (converter.getType() == "string")
        o << YELLOW << converter.getInput() << RESET " can't be converted to char, int, float, double." << std::endl;
    else if (converter.getIsErange() == true)
        o << converter.getInput() << " : " << GREEN << converter.getType() << RESET << RED " is out of range" RESET
          << std::endl;
    else
    {
        converter.printChar(o);
        converter.printInt(o);
        converter.printFloat(o);
        converter.printDouble(o);
    }
    return (o);
}
