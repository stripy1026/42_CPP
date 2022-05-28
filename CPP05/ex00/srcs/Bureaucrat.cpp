#include "Bureaucrat.hpp"

Bureaucrat()
{
}

~Bureaucrat()
{
}

Bureaucrat(const Bureaucrat &src) : m_name(src.m_name), m_grade(src.m_grade)
{
}

Bureaucrat &operator=(const Bureaucrat &rhs)
{
    if (this == &rhs)
        return (*this);
    m_name = rhs.m_name;
    m_grade = rhs.m_grade;
    return (*this);
}

Bureaucrat(const std::string &name, const int grade) : m_name(name), m_grade(grade)
{
}

const std::string &getName() const
{
    return (m_name);
}

const int &getGrade() const
{
    return (m_grade);
}

void incrementGrade(const int num)
{
    m_grade -= num;
}

void decrementGrade(const int num)
{
    m_grade += num;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
    o << GREEN << bureaucrat.getName() << RESET ", bureaucrat grade " GREEN << bureaucrat.getGrade() << RESET;
    return (o);
}