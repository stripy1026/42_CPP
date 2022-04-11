#include "Harl.hpp"

Harl::Harl()
{
    std::cout << GREEN << "Harl comes to your restaurent." << RESET << std::endl;
}

Harl::~Harl()
{
    std::cout << YELLOW << "Harl has left from your restaurent." << RESET << std::endl;
}

void Harl::debug() const
{
    std::cout << "I love having extra bacon for my Mom's touch fillet burger. I really do!" << std::endl;
}

void Harl::info() const
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! if "
                 "you did, I wouldn’t be asking for more!"
              << std::endl;
}

void Harl::warining() const
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started "
                 "working here since last month."
              << std::endl;
}

void Harl::error() const
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::noLevel() const
{
    std::cout << RED << "Invalid level." << RESET << std::endl;
}

void Harl::complain(std::string level) const
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functionArray[5])() const = {&Harl::debug, &Harl::info, &Harl::warining, &Harl::error, &Harl::noLevel};
    int i = 0;
    while (i < 4 && levels[i] != level)
        ++i;
    std::cout << MAGENTA << "[" << level << "] " << RESET;
    (this->*functionArray[i])();
}
