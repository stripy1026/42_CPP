#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <exception>
#include <iostream>

#include "color.hpp"

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

    const std::string &getName() const;
    const int &getGrade() const;

    void incrementGrade(const int num);
    void decrementGrade(const int num);

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
