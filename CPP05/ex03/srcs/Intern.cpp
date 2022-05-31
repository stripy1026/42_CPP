#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern &Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    return (*this);
}

Form *Intern::makeForm(const std::string &name, const std::string &target)
{
    const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    Form *(Intern::*formMakers[4])(const std::string &target)
        const = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm,
                 &Intern::makePresidentialPardonForm, &Intern::makeWrongForm};
    int i = 0;
    while (i < 3 && name != names[i])
        ++i;
    Form *form = (this->*formMakers[i])(target);
    std::cout << YELLOW "Intern creates " RESET << form->getName() << std::endl;
    return (form);
}

Form *Intern::makeShrubberyCreationForm(const std::string &target) const
{
    return (new ShrubberyCreationForm(target));
}

Form *Intern::makeRobotomyRequestForm(const std::string &target) const
{
    return (new RobotomyRequestForm(target));
}

Form *Intern::makePresidentialPardonForm(const std::string &target) const
{
    return (new PresidentialPardonForm(target));
}

Form *Intern::makeWrongForm(const std::string &target) const
{
    (void)target;
    throw WrongNameException();
    return (NULL);
}

const char *Intern::WrongNameException::what() const throw()
{
    return ("form name does not exist");
}