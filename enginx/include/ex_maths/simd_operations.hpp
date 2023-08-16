#ifndef SIMD_OPERATIONS_HPP
#define SIMD_OPERATIONS_HPP

#include <iostream>
#include <vector>
#include <array>

#include "defines.h"

namespace ex_math
{
    using Array4f = std::array<f32, 4>; // List of 4 single precision floating point numbers
    using Array8f = std::array<f32, 8>; // List of 8 single precision floating point numbers
    
    Array4f simd_add(const Array4f& array_1, const Array4f& array_2);
    Array8f simd_add(const Array8f& array_1, const Array8f& array_2);
        
}

#endif // SIMD_OPERATIONS_HPP