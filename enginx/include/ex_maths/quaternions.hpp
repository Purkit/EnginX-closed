#ifndef QUARTERNIAN_HPP
#define QUARTERNIAN_HPP

#include <array>
#include <ex_maths/square_root.h>
#include "defines.h"

namespace ex_math
{
    struct Quarternian
    {
        f32 x;
        f32 y;
        f32 z;
        f32 w;

        Quarternian();
        Quarternian(f32 _x, f32 _y, f32 _z, f32 _w);

        void MakeIdentity();

        f32 Normal() const;

        void Normalize();
        Quarternian Normalized() const;

        void Conjugate();
        Quarternian Conjugated() const;

        void Inverse();
        Quarternian Inversed() const;
    }; 
}

#endif // QUARTERNIAN_HPP