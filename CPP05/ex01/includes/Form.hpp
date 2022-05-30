#ifndef _FORM_HPP_
#define _FORM_HPP_

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "color.hpp"

class Bureaucrat;

class Form
{
  private:
    const std::string m_name;
    bool m_signed;
    const int m_sign_grade;
    const int m_execute_grade;

    Form();

  public:
    virtual ~Form();
    Form(const Form &src);
    Form &operator=(const Form &rhs);

    Form(const std::string name, const int sign_grade, const int execute_grade);

    void beSigned(const Bureaucrat &bureaucrat);

    const std::string &getName() const;
    const bool &getSigned() const;
    const int &getSignGrade() const;
    const int &getExecuteGrade() const;

    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, const Form &form);

#endif // _FORM_HPP_