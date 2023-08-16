#include <ex_maths/conversions.hpp>

namespace ex_math
{
    f32 degree_to_radians(f32 degree)
    {
        return (degree * 0.0175);
    }

    f32 radian_to_degrees(f32 radian)
    {
        return (radian * 57.2957);
    }

}