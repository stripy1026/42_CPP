#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Form form("tedious task", 10, 4);
    Bureaucrat bob("Bob", 11);

    std::cout << form << std::endl;
    std::cout << bob << std::endl;

    bob.signForm(form);
    bob.incrementGrade(1);
    bob.signForm(form);

    std::cout << std::endl << form << std::endl;

    return (0);
}
