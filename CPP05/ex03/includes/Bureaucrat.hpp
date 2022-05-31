#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <exception>
#include <iostream>

#include "Form.hpp"
#include "color.hpp"

class Form;

class Bureaucrat
{
  private:
    const std::string m_name;
    int m_grade;

    Bureaucrat();

  public:
    virtual ~Bureaucrat();
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &rhs);

    Bureaucrat(const std::string &name, const int grade);

    void incrementGrade(const int num);
    void decrementGrade(const int num);

    void signForm(Form &form) const;
    void executeForm(const Form &form) const;

    const std::string &getName() const;
    const int &getGrade() const;

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

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif // _BUREAUCRAT_HPP_
