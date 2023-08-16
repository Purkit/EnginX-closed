#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vector.hpp"
#include "defines.h"

namespace ex_math // ** exginx math namespace
{
    // * //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// * //
    // * ---------------------------------- MATRIX TYPES DESIGNED FOR TRADITIONAL MATH LIBRARY ---------------------------------- * //
    // * //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// * //

    // * 2x2 Matrix
    struct Matrix2x2
    {
        f32 a11, a12;
        f32 a21, a22;

        Matrix2x2();
        Matrix2x2(f32 _i);
        Matrix2x2
        (
            f32 _i11, f32 _i12,
            f32 _i21, f32 _i22
        );

        void MakeIdentity();
        void Transpose();
        void Inverse();

        f32 Determinant() const;
        
        void operator=(const std::array<f32, 4>&& data);

        Matrix2x2 operator+(const Matrix2x2& to_add) const;
        friend Matrix2x2 operator*(const f32& scalar, const Matrix2x2& matrix_to_scale);
    };

    // * 3x3 Matrix
    struct Matrix3x3
    {
        f32 a11, a12, a13;
        f32 a21, a22, a23;
        f32 a31, a32, a33;

        Matrix3x3();
        Matrix3x3(f32 _i);
        Matrix3x3
        (
            f32 _i11, f32 _i12, f32 _i13,
            f32 _i21, f32 _i22, f32 _i23,
            f32 _i31, f32 _i32, f32 _i33
        );

        void MakeIdentity();
        void Transpose();
        void Inverse();

        f32 Determinant() const;
        
        void operator=(const std::array<f32, 9>&& data);

        Matrix3x3 operator+(const Matrix3x3& to_add) const;
        friend Matrix3x3 operator*(const f32& scalar, const Matrix3x3& matrix_to_scale);
    };

    // * 4x4 Matrix
    struct Matrix4x4
    {
        f32 a11, a12, a13, a14;
        f32 a21, a22, a23, a24;
        f32 a31, a32, a33, a34;
        f32 a41, a42, a43, a44;

        Matrix4x4();
        Matrix4x4(f32 _i);
        Matrix4x4
        (
            f32 _i11, f32 _i12, f32 _i13, f32 _i14,
            f32 _i21, f32 _i22, f32 _i23, f32 _i24,
            f32 _i31, f32 _i32, f32 _i33, f32 _i34,
            f32 _i41, f32 _i42, f32 _i43, f32 _i44
        );

        void MakeIdentity();
        void Transpose();
        void Inverse();

        f32 Determinant() const;
        
        void operator=(const std::array<f32, 16>&& data);

        Matrix4x4 operator+(const Matrix4x4& to_add) const;
        friend Matrix4x4 operator*(const f32& scalar, const Matrix4x4& matrix_to_scale);
    };

    // * //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// * //
    // * -------------------------------- MATRIX TYPES DESIGNED FOR SIMD ACCLERATED MATH LIBRARY -------------------------------- * //
    // * //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// * //

    // * 4x4 Matrix
    /* struct Matrix4x4
    {
        Matrix4x4();
        Matrix4x4(f32 _i);
        Matrix4x4
        (
            f32 _i11, f32 _i12, f32 _i13, f32 _i14,
            f32 _i21, f32 _i22, f32 _i23, f32 _i24,
            f32 _i31, f32 _i32, f32 _i33, f32 _i34,
            f32 _i41, f32 _i42, f32 _i43, f32 _i44
        );

        f32 Determinant() const;
        
        void operator=(const std::array<f32, 16>&& data);

        Matrix4x4 operator+(const Matrix4x4& to_add) const;
        friend Matrix4x4 operator*(const int& scalar, const Matrix4x4& matrix_to_scale);

        f32 a11, a12, a13, a14;
        f32 a21, a22, a23, a24;
        f32 a31, a32, a33, a34;
        f32 a41, a42, a43, a44;
    }; */
}

#endif // MATRIX_HPP