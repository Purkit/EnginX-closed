#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "defines.h"

template<typename T>
void Swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

#endif // UTILITY_HPP