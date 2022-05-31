#ifndef _PRESIDENTIAL_PARDON_FORM_HPP_
#define _PRESIDENTIAL_PARDON_FORM_HPP_

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
  private:
    std::string m_target;

    PresidentialPardonForm();

  public:
    virtual ~PresidentialPardonForm();

    PresidentialPardonForm(const PresidentialPardonForm &src);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

    PresidentialPardonForm(const std::string &target);

    void execute(const Bureaucrat &bureaucrat) const;
};

#endif // _PRESIDENTIAL_PARDON_FORM_HPP_
