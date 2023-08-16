#include <ex_maths/quaternions.hpp>

namespace ex_math
{
    Quarternian::Quarternian()
        : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
    {}

    Quarternian::Quarternian(f32 _x, f32 _y, f32 _z, f32 _w)
        : x(_x), y(_y), z(_z), w(_w)
    {}

    void Quarternian::MakeIdentity()
    {
        x = y = z = 0.0f;
        w = 1.0f;
    }

    f32 Quarternian::Normal() const
    {
        return ex_sqrt( x*x + y*y + z*z + w*w );
    }

    void Quarternian::Normalize()
    {
        f32 normal = ex_sqrt( x*x + y*y + z*z + w*w );

        x = x / normal;
        y = y / normal;
        z = z / normal;
        w = w / normal;
    }

    Quarternian Quarternian::Normalized() const
    {
        f32 normal = ex_sqrt( x*x + y*y + z*z + w*w );

        return Quarternian(
            x / normal,
            y / normal,
            z / normal,
            w / normal
        );
    }

    void Quarternian::Conjugate()
    {
        x = -x;
        y = -y;
        z = -z;
        w =  w;
    }

    Quarternian Quarternian::Conjugated() const
    {
        return Quarternian( -x, -y, -z, w);
    }

    void Quarternian::Inverse()
    {
        f32 normal = ex_sqrt( x*x + y*y + z*z + w*w );

        x = -x / normal;
        y = -y / normal;
        z = -z / normal;
        w =  w / normal;
    }

    Quarternian Quarternian::Inversed() const
    {
        f32 normal = ex_sqrt( x*x + y*y + z*z + w*w );

        return Quarternian(
            -x / normal,
            -y / normal,
            -z / normal,
            w / normal
        );
    }
}