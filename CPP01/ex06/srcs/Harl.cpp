#include "Harl.hpp"

Harl::Harl()
{
    std::cout << GREEN << "Harl comes to your restaurent." << RESET << std::endl;
}

Harl::~Harl()
{
    std::cout << YELLOW << "Harl has left from your restaurent." << RESET << std::endl;
}

void Harl::debug()
{
    std::cout << MAGENTA << "[DEBUG] " << RESET
              << "I love having extra bacon for my Mom's touch fillet burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << MAGENTA << "[INFO] " << RESET
              << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! if "
                 "you did, I wouldn’t be asking for more!"
              << std::endl;
}

void Harl::warining()
{
    std::cout << MAGENTA << "[WARNING] " << RESET
              << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started "
                 "working here since last month."
              << std::endl;
}

void Harl::error()
{
    std::cout << MAGENTA << "[ERROR] " << RESET << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

void Harl::complain(std::string level)
{
	unsigned char hashVal;

	hashVal = level.length * 1000 + level[0] * 1000 + level[1] * 100;

	level 

	[0] ("DEBUG") -> debug();
	[1] 


	[4] -> default();

	...
	[255] -> 

	functionArray;

	short.max(); -> default();

	functionArray(decode(level));

	val -> len, word front[7] short 
    if (level == "DEBUG")
        debug();
    else if (level == "INFO")
        info();
    else if (level == "WARNING")
        warining();
    else if (level == "ERROR")
        error();
    else
        handleError(ERR_ARGNUM, EXIT_FAILURE);
}
