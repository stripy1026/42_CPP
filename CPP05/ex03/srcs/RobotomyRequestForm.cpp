#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : Form(src.getName(), src.getSignGrade(), src.getExecuteGrade()), m_target(src.m_target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this == &rhs)
        return (*this);
    m_target = rhs.m_target;
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("Robotomy request", 72, 45), m_target(target)
{
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
    if (!getSigned())
        throw ExecuteNotSignedException();
    if (getExecuteGrade() < bureaucrat.getGrade())
        throw GradeTooLowException();
    std::cout << "* some drilling noises *" << std::endl;
    if (rand() % 2)
    {
        std::cout << GREEN << m_target << RESET " has been robotomized successfully." << std::endl;
    }
    else
    {
        std::cout << GREEN << m_target << RESET " : robotomy failed." << std::endl;
    }
}
