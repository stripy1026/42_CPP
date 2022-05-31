#ifndef _SHRUBBERY_CREATION_FORM_HPP_
#define _SHRUBBERY_CREATION_FORM_HPP_

#include <fstream>

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
  private:
    std::string m_target;

    ShrubberyCreationForm();

  public:
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

    ShrubberyCreationForm(const std::string &target);

    virtual void execute(const Bureaucrat &bureaucrat) const;
};

#endif // _SHRUBBERY_CREATION_FORM_HPP_
