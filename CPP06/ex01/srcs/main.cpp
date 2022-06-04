#include <iostream>

#include "color.hpp"
#include "serialize.hpp"

int main()
{
    Data *data = new Data(42);
    uintptr_t serialized;
    Data *deserialized;

    std::cout << YELLOW "data ptr : " RESET << data << std::endl;
    std::cout << YELLOW "data value : " RESET << data->getValue() << std::endl;

    serialized = serialize(data);
    std::cout << YELLOW "serialized data(decimal) : " RESET << serialized << std::endl;
    std::cout << YELLOW "serialized data(hex) : " RESET << std::hex << serialized << std::endl;

    deserialized = deserialize(serialized);
    std::cout << YELLOW "deserialized data : " RESET << deserialized << std::endl;
    std::cout << YELLOW "deserialized data value : " RESET << deserialized->getValue() << std::endl;

    delete data;

    return (0);
}
