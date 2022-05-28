#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <exception>
#include <iostream>

#include "color.hpp"

class Bureaucrat
{
  private:
    const std::string m_name;
    const int m_grade;

    Bureaucrat();

  public:
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &rhs);

    Bureaucrat(const std::string &name, const int grade);

    const std::string &getName() const;
    const int &getGrade() const;

    void incrementGrade(const int num);
    void decrementGrade(const int num);
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif // _BUREAUCRAT_HPP_
