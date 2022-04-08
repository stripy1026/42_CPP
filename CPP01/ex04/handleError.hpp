#ifndef _HANDLE_ERROR_HPP_
#define _HANDLE_ERROR_HPP_

#include <iostream>
#include <string>

#include "color.hpp"

#define ERR_ARGNUM "Use 3 arguments : filename, string, string to replace."
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int handleError(std::string message, int value);

#endif // _HANDLE_ERROR_HPP_