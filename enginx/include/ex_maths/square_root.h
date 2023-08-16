#ifndef FAST_SQUARE_H
#define FAST_SQUARE_H

#include <immintrin.h>

namespace ex_math
{
    float ex_sqrt(float number);
    float ex_inv_sqrt(float number);
    __m128 Q_rsqrt_sse(__m128 number);
}

#endif // FAST_SQUARE_H