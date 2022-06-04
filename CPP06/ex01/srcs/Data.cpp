#include "Data.hpp"

Data::Data()
{
}

Data::Data(const Data &src)
{
    (void)src;
}

Data &Data::operator=(const Data &rhs)
{
    (void)rhs;
    return (*this);
}

Data::~Data()
{
}

Data::Data(int value) : m_value(value)
{
}

int Data::getValue() const
{
    return (m_value);
}
