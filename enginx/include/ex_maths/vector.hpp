#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <array>
#include "defines.h"

namespace ex_math // ** exginx math namespace
{
    // * 2D Vectors
    struct Vector2f
    {
        f32 x;
        f32 y;

        Vector2f();
        Vector2f(f32 _i);
        Vector2f(f32 _x, f32 _y);

        f32 Length() const;
        f32 LengthSqr() const;

        Vector2f Normalized() const;
        void Normalize();

        Vector2f operator+(const Vector2f& to_add) const;
        friend Vector2f operator*(const f32& scalar, const Vector2f& to_scale);
    };

    // * 3D Vectors
    struct Vector3f
    {
        f32 x;
        f32 y;
        f32 z;

        Vector3f();
        Vector3f(f32 _i);
        Vector3f(f32 _x, f32 _y, f32 _z);

        f32 Length() const;
        f32 LengthSqr() const;

        Vector3f Normalized() const;
        void Normalize();

        Vector3f operator+(const Vector3f& to_add) const;
        friend Vector3f operator*(const f32& scalar, const Vector3f& to_scale);
    };

    // * 4D Vectors
    struct Vector4f
    {
        f32 x;
        f32 y;
        f32 z;
        f32 w;

        Vector4f();
        Vector4f(f32 _i);
        Vector4f(f32 _x, f32 _y, f32 _z, f32 _w);

        f32 Length() const;
        f32 LengthSqr() const;

        Vector4f Normalized() const;
        void Normalize();

        Vector4f operator+(const Vector4f& to_add) const;
        friend Vector4f operator*(const f32& scalar, const Vector4f& to_scale);
    };

}

#endif // VECTOR_HPP