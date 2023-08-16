#include <ex_maths/square_root.h>

float ex_math::ex_sqrt(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    float a =number;
    
    i = * (long*) &y;
    i = 0x1fbd3f7c + (i>>1);
    y = * (float*) &i;

    y = (y + (a/y)) / 2;  // 1st iteration
    y = (y + (a/y)) / 2;  // 2nd iteration
    
    return y;
}

float ex_math::ex_inv_sqrt(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    
    i = * (long*) &y;
    i = 0x5f3759df - (i>>1);
    y = * (float*) &i;

    y = y * (threehalfs - (x2 * y * y));  // 1st iteration
    y = y * (threehalfs - (x2 * y * y));  // 2nd iteration

    return y;
}

__m128 ex_math::Q_rsqrt_sse(__m128 number)
{
    __m128i i;
	__m128 x2, y;
	const __m128 threehalfs = _mm_set1_ps(1.5f);

	x2 = _mm_mul_ps(number, _mm_set_ps1(0.5f));
	y = number;
	i = *(__m128i *)&y;                                                          // evil floating point bit level hacking
	i = _mm_sub_epi32(_mm_set1_epi32(0x5f3759df), _mm_srli_epi32(i, 1));         // what the fuck?
	y = *(__m128 *)&i;
	y = _mm_mul_ps(y, _mm_sub_ps(threehalfs, _mm_mul_ps(x2, _mm_mul_ps(y, y)))); // 1st iteration
	// y = _mm_mul_ps(y, _mm_sub_ps(threehalfs, _mm_mul_ps(x2, _mm_mul_ps(y, y)))); // 2nd iteration, this can be removed

	return y;
}

// _mm_rsqrt_ps(x) took 13.855000ms