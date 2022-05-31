#ifndef _ROBOTOMY_REQUEST_FORM_HPP_
#define _ROBOTOMY_REQUEST_FORM_HPP_

#include <cstdlib>
#include <ctime>

#include "Form.hpp"

class RobotomyRequestForm : public Form
{

  private:
    std::string m_target;

    RobotomyRequestForm();

  public:
    virtual ~RobotomyRequestForm();

    RobotomyRequestForm(const RobotomyRequestForm &src);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

    RobotomyRequestForm(const std::string &target);

    void execute(const Bureaucrat &bureaucrat) const;
};

#endif // _ROBOTOMY_REQUEST_FORM_HPP_
