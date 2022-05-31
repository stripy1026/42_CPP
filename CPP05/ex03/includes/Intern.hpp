#ifndef _INTERN_HPP_
#define _INTERN_HPP_

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
  private:
    Form *makeShrubberyCreationForm(const std::string &target) const;
    Form *makeRobotomyRequestForm(const std::string &target) const;
    Form *makePresidentialPardonForm(const std::string &target) const;
    Form *makeWrongForm(const std::string &target) const;

  public:
    Intern();
    virtual ~Intern();
    Intern(const Intern &src);
    Intern &operator=(const Intern &rhs);

    Form *makeForm(const std::string &name, const std::string &target);

    class WrongNameException : public std::exception
    {
      public:
        virtual const char *what() const throw();
    };
};

#endif // _INTERN_HPP_