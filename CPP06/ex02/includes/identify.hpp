#ifndef _IDENTIFY_HPP_
#define _IDENTIFY_HPP_

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate();
void identify(Base *p);
void identify(Base &p);

#endif // _IDENTIFY_HPP_
