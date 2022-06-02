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
}

const std::string &Converter::getInput() const
{
    return (m_input);
}

const std::string &Converter::getType() const
{
    return (m_type);
}

void Converter::detectType()
{
    if ((m_input.length() == 1) && ((32 < m_input[0] && m_type[0] < 48) || (57 < m_input[0] && m_input[0] < 127)))
    {
        m_type = "char";
        return;
    }
    for (int i = 0; i < m_type.length(); ++i)
    {
		
    }
}
