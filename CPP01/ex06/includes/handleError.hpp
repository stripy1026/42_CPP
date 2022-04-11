#ifndef _HANDLE_ERROR_HPP_
#define _HANDLE_ERROR_HPP_

#include <cstdlib>
#include <iostream>
#include <string>

#include "color.hpp"

#define ERR_ARGNUM "Use 4 arguments : DEBUG, INFO, WARNING, ERROR"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int handleError(std::string message, int value);

#endif // _HANDLE_ERROR_HPP_
