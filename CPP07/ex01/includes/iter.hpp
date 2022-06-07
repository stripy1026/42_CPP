#ifndef _ITER_HPP_
#define _ITER_HPP_

#include <iostream>

template <typename T> void iter(const T *arr, const size_t size, void f(const T &))
{
    for (size_t i = 0; i < size; ++i)
        f(arr[i]);
}

template <typename T> void testFunction(const T &data)
{
    std::cout << data << " ";
}

#endif // _ITER_HPP_
