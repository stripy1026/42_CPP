#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : Form(src.getName(), src.getSignGrade(), src.getExecuteGrade()), m_target(src.m_target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this == &rhs)
        return *this;
    m_target = rhs.m_target;
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form("ShrubberyCreationForm", 145, 137), m_target(target)
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
    std::ofstream out;

    if (!getSigned())
        throw ExecuteNotSignedException();
    if (getExecuteGrade() < bureaucrat.getGrade())
        throw GradeTooLowException();
    out.open((m_target + "_shrubbery").c_str());
    if (out.good() == false)
        throw FileOpeningFailException();
    out << "       _-_" << std::endl;
    out << "    /~~   ~~\\" << std::endl;
    out << " /~~         ~~\\" << std::endl;
    out << "{               }" << std::endl;
    out << " \\  _-     -_  /" << std::endl;
    out << "   ~  \\\\ //  ~" << std::endl;
    out << "_- -   | | _- _" << std::endl;
    out << "  _ -  | |   -_" << std::endl;
    out << "      // \\\\" << std::endl;
    out.close();
}
