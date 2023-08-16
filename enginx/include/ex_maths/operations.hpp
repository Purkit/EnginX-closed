#include "vector.hpp"
#include "matrix.hpp"
#include "quaternions.hpp"

namespace ex_math
{
    // * Dot Product
    f32 Dot(const Vector2f& lhs, const Vector2f& rhs);
    f32 Dot(const Vector3f& lhs, const Vector3f& rhs);
    f32 Dot(const Vector4f& lhs, const Vector4f& rhs);
    f32 Dot(const Quarternian& lhs, const Quarternian& rhs);

    // * Cross Product
    f64 Cross(const Vector2f& lhs, const Vector2f& rhs);
    Vector3f Cross(const Vector3f& lhs, const Vector3f& rhs);
    Vector4f Cross(const Vector4f& lhs, const Vector4f& rhs);

    // * Matrix-Matrix Multiplication (Composition of transformation):
    Matrix2x2 operator*(const Matrix2x2& lhs, const Matrix2x2& rhs);
    Matrix3x3 operator*(const Matrix3x3& lhs, const Matrix3x3& rhs);
    Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs);

    // * Matrix-vector Multiplication (Transformation of Vectors):
    Vector2f operator*(const Matrix2x2& mat, const Vector2f& vec);
    Vector2f operator*(const Vector2f& vec, const Matrix2x2& mat);

    Vector3f operator*(const Matrix3x3& mat, const Vector3f& vec);
    Vector3f operator*(const Vector3f& vec, const Matrix3x3& mat);

    Vector4f operator*(const Matrix4x4& mat, const Vector4f& vec);
    Vector4f operator*(const Vector4f& vec, const Matrix4x4& mat);

    // * Quaternion-Quaternion Multiplication:
    Quarternian operator*(const Quarternian& lhs, const Quarternian& rhs);    

    // * Determinant of Matrices:
    f64 DeterminantOf(const Matrix2x2& mat);
    f64 DeterminantOf(const Matrix3x3& mat);
    f64 DeterminantOf(const Matrix4x4& mat);

    // * Inverse of Matrices:
    Matrix2x2 InverseOf(const Matrix2x2& mat);
    Matrix3x3 InverseOf(const Matrix3x3& mat);
    Matrix4x4 InverseOf(const Matrix4x4& mat);

    // * Transpose of Matrices:
    Matrix2x2 TransposeOf(const Matrix2x2& mat);
    Matrix3x3 TransposeOf(const Matrix3x3& mat);
    Matrix4x4 TransposeOf(const Matrix4x4& mat);
    
}
