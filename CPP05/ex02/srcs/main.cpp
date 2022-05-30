#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    Bureaucrat *p = NULL;
    try
    {
        p = new Bureaucrat("Bob", 150);
    }
    catch (std::exception &e)
    {
        std::cerr << RED "Error : " RESET << e.what() << std::endl;
    }
    if (!p)
        return (0);
    std::cout << *p << std::endl;
    delete p;
    return (0);
}
