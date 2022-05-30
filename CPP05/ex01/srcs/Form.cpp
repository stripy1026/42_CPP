#include "Form.hpp"

Form::Form() : m_name(), m_sign_grade(), m_execute_grade()
{
}

Form::~Form()
{
}

Form::Form(const Form &src)
    : m_name(src.m_name), m_signed(src.m_signed), m_sign_grade(src.m_sign_grade), m_execute_grade(src.m_execute_grade)
{
}

Form &Form::operator=(const Form &rhs)
{
    if (this == &rhs)
        return (*this);
    m_signed = rhs.m_signed;
    return (*this);
}

Form::Form(const std::string name, const int sign_grade, const int execute_grade)
    : m_name(name), m_signed(false), m_sign_grade(sign_grade), m_execute_grade(execute_grade)
{
    if (sign_grade < 1 || execute_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw GradeTooLowException();
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (m_sign_grade < bureaucrat.getGrade())
        throw GradeTooLowException();
    m_signed = true;
}

const std::string &Form::getName() const
{
    return (m_name);
}

const bool &Form::getSigned() const
{
    return (m_signed);
}

const int &Form::getSignGrade() const
{
    return (m_sign_grade);
}

const int &Form::getExecuteGrade() const
{
    return (m_execute_grade);
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high. valid grade must be 1 ~ 150.");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low. valid grade must be 1 ~ 150.");
}

std::ostream &operator<<(std::ostream &o, const Form &form)
{
    o << "form " GREEN << form.getName() << RESET " signed : " GREEN << form.getSigned() << RESET " sign_grade : " GREEN
      << form.getSignGrade() << RESET " execute_grade : " GREEN << form.getExecuteGrade() << RESET << std::endl;
    return (o);
}
