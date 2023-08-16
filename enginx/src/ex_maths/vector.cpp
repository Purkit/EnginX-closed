#include <ex_maths/vector.hpp>
#include <ex_maths/square_root.h>

namespace ex_math
{
    // * VECTOR2D :
    Vector2f::Vector2f() : x(0), y(0) {}
    Vector2f::Vector2f(f32 _i) : x(_i), y(_i) {}
    Vector2f::Vector2f(f32 _x, f32 _y) : x(_x), y(_y) {}

    f32 Vector2f::Length() const
    {
        return ex_math::ex_sqrt(x*x + y*y);        
    }

    f32 Vector2f::LengthSqr() const
    {
        return (x*x + y*y);
    }

    Vector2f Vector2f::Normalized() const
    {
        return Vector2f(
                            x * ex_math::ex_inv_sqrt(x*x + y*y),
                            y * ex_math::ex_inv_sqrt(x*x + y*y)
                       );
    }

    void Vector2f::Normalize()
    {
        // TODO: In many part of our code we are computing the ex_inv_sqrt of the same thing multiple time. So it would be more efficient if we store the ex_inv_sqrt in some variable.  
        x = x * ex_math::ex_inv_sqrt(x*x + y*y);
        y = y * ex_math::ex_inv_sqrt(x*x + y*y);
    }

    Vector2f Vector2f::operator+(const Vector2f& to_add) const
    {
        return Vector2f(x + to_add.x, y + to_add.y);
    }

    Vector2f operator*(const f32& scalar, const Vector2f& to_scale)
    {
        return Vector2f(scalar * to_scale.x, scalar * to_scale.y);        
    }

    
    // * VECTOR3D :
    Vector3f::Vector3f() : x(0), y(0), z(0) {}
    Vector3f::Vector3f(f32 _i) : x(_i), y(_i), z(_i) {}
    Vector3f::Vector3f(f32 _x, f32 _y, f32 _z) : x(_x), y(_y), z(_z) {}

    f32 Vector3f::Length() const
    {
        return ex_math::ex_sqrt(x*x + y*y + z*z);
    }

    f32 Vector3f::LengthSqr() const
    {
        return (x*x + y*y + z*z);
    }

    Vector3f Vector3f::Normalized() const
    {
        return Vector3f(
                            x * ex_math::ex_inv_sqrt(x*x + y*y + z*z),
                            y * ex_math::ex_inv_sqrt(x*x + y*y + z*z),
                            z * ex_math::ex_inv_sqrt(x*x + y*y + z*z)
                       );
    }

    void Vector3f::Normalize()
    {
        x = x * ex_math::ex_inv_sqrt(x*x + y*y + z*z);
        y = y * ex_math::ex_inv_sqrt(x*x + y*y + z*z);
        z = z * ex_math::ex_inv_sqrt(x*x + y*y + z*z);
    }

    Vector3f Vector3f::operator+(const Vector3f& to_add) const
    {
        return Vector3f(x + to_add.x, y + to_add.y, z + to_add.z);
    }

    Vector3f operator*(const f32& scalar, const Vector3f& to_scale)
    {
        return Vector3f(scalar * to_scale.x, scalar * to_scale.y, scalar * to_scale.z);
    }


    // * VECTOR4D :
    Vector4f::Vector4f() : w(0), x(0), y(0), z(0) {}
    Vector4f::Vector4f(f32 _i) : w(_i), x(_i), y(_i), z(_i) {}
    Vector4f::Vector4f(f32 _x, f32 _y, f32 _z, f32 _w) : x(_x), y(_y), z(_z), w(_w) {}

    f32 Vector4f::Length() const
    {
        return ex_math::ex_sqrt(w*w + x*x + y*y + z*z);
    }

    f32 Vector4f::LengthSqr() const
    {
        return (w*w + x*x + y*y + z*z);
    }

    Vector4f Vector4f::Normalized() const
    {
        return Vector4f(
                            w * ex_math::ex_inv_sqrt(w*w + x*x + y*y + z*z),
                            x * ex_math::ex_inv_sqrt(w*w + x*x + y*y + z*z),
                            y * ex_math::ex_inv_sqrt(w*w + x*x + y*y + z*z),
                            z * ex_math::ex_inv_sqrt(w*w + x*x + y*y + z*z)
                       );
    }

    void Vector4f::Normalize()
    {
        w = w * ex_math::ex_inv_sqrt(w*w + x*x + y*y + z*z);
        x = x * ex_math::ex_inv_sqrt(w*w + x*x + y*y + z*z);
        y = y * ex_math::ex_inv_sqrt(w*w + x*x + y*y + z*z);
        z = z * ex_math::ex_inv_sqrt(w*w + x*x + y*y + z*z);
    }

    Vector4f Vector4f::operator+(const Vector4f& to_add) const
    {
        return Vector4f(w + to_add.w, x + to_add.x, y + to_add.y, z + to_add.z);        
    }

    Vector4f operator*(const f32& scalar, const Vector4f& to_scale)
    {
        return Vector4f(scalar * to_scale.w, scalar * to_scale.x, scalar * to_scale.y, scalar * to_scale.z);
    }


}