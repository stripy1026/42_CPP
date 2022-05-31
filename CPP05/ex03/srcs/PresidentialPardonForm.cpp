#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : Form(src.getName(), src.getSignGrade(), src.getExecuteGrade()), m_target(src.m_target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    if (this == &rhs)
        return *this;
    m_target = rhs.m_target;
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form("PresidentialPardonForm", 25, 5), m_target(target)
{
}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
    if (!getSigned())
        throw ExecuteNotSignedException();
    if (getExecuteGrade() < bureaucrat.getGrade())
        throw GradeTooLowException();
    std::cout << GREEN << m_target << RESET " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
