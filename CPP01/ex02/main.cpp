#include <iostream>
#include <string>

int main()
{
    std::string str("HI THIS IS BRAIN");
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "[ **** The memory address **** ]" << std::endl;
    std::cout << "of the string variable : " << &str << std::endl;
    std::cout << "held by stringPTR : " << stringPTR << std::endl;
    std::cout << "held by stringREF : " << &stringREF << std::endl;

    std::cout << "[ **** The value **** ]" << std::endl;
    std::cout << "of the string variable : " << str << std::endl;
    std::cout << "pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "pointed to by stringREF : " << stringREF << std::endl;

    return (0);
}