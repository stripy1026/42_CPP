#ifndef _SERIALIZATION_HPP_
#define _SERIALIZATION_HPP_

#include <stdint.h>

#include "Data.hpp"

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif // _SERIALIZATION_HPP_
