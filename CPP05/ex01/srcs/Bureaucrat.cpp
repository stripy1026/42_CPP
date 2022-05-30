#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : m_name(src.m_name), m_grade(src.m_grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (this == &rhs)
        return (*this);
    m_grade = rhs.m_grade;
    return (*this);
}

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : m_name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    m_grade = grade;
}

void Bureaucrat::incrementGrade(const int num)
{
    if (m_grade - num < 1)
        throw GradeTooHighException();
    m_grade -= num;
}

void Bureaucrat::decrementGrade(const int num)
{
    if (m_grade + num > 150)
        throw GradeTooLowException();
    m_grade += num;
}

void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << YELLOW << m_name << RESET " signs " YELLOW << form.getName() << RESET << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << YELLOW << m_name << RESET " couldn't sign " YELLOW << form.getName() << RESET " because " << RED
                  << e.what() << RESET << std::endl;
    }
}

const std::string &Bureaucrat::getName() const
{
    return (m_name);
}

const int &Bureaucrat::getGrade() const
{
    return (m_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high. valid grade must be 1 ~ 150.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low. valid grade must be 1 ~ 150.");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
    o << GREEN << bureaucrat.getName() << RESET ", bureaucrat grade " GREEN << bureaucrat.getGrade() << RESET;
    return (o);
}