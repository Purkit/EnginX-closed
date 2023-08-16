#include <ex_maths/operations.hpp>

namespace ex_math
{
    f32 Dot(const Vector2f& lhs, const Vector2f& rhs)
    {
        return ( (lhs.x * rhs.x) + (lhs.y * rhs.y) );
    }

    f32 Dot(const Vector3f& lhs, const Vector3f& rhs)
    {
        return ( (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) );
    }

    f32 Dot(const Vector4f& lhs, const Vector4f& rhs)
    {
        return ( (lhs.w * rhs.w) + (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) );
    }

    f32 Dot(const Quarternian& lhs, const Quarternian& rhs)
    {
        return ( (lhs.w * rhs.w) + (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) );
    }

    f64 Cross(const Vector2f& lhs, const Vector2f& rhs)
    {
        return ((lhs.x * rhs.y) - (lhs.y * rhs.x));
    }

    Vector3f Cross(const Vector3f& lhs, const Vector3f& rhs)
    {
        Vector3f result;

        result.x = lhs.y * rhs.z - lhs.z * rhs.y;
        result.y = lhs.z * rhs.x - lhs.x * rhs.z;
        result.z = lhs.x * rhs.y - lhs.y * rhs.x;

        return result;
    }

    Vector4f Cross(const Vector4f& lhs, const Vector4f& rhs)
    {

    }

    // * Matrix-Matrix Multiplication (Composition of transformation):
    Matrix2x2 operator*(const Matrix2x2& lhs, const Matrix2x2& rhs)
    {
        Matrix2x2 result;

        result.a11 = (lhs.a11 * rhs.a11) + (lhs.a12 * rhs.a21);
        result.a12 = (lhs.a11 * rhs.a12) + (lhs.a12 * rhs.a22);

        result.a21 = (lhs.a21 * rhs.a11) + (lhs.a22 * rhs.a21);
        result.a22 = (lhs.a21 * rhs.a12) + (lhs.a22 * rhs.a22);

        return result;
    }

    Matrix3x3 operator*(const Matrix3x3& lhs, const Matrix3x3& rhs)
    {
        Matrix3x3 result;

        result.a11 = (lhs.a11 * rhs.a11) + (lhs.a12 * rhs.a21) + (lhs.a13 * rhs.a31);
        result.a12 = (lhs.a11 * rhs.a12) + (lhs.a12 * rhs.a22) + (lhs.a13 * rhs.a32);
        result.a13 = (lhs.a11 * rhs.a13) + (lhs.a12 * rhs.a23) + (lhs.a13 * rhs.a33);

        result.a21 = (lhs.a21 * rhs.a11) + (lhs.a22 * rhs.a21) + (lhs.a23 * rhs.a31);
        result.a22 = (lhs.a21 * rhs.a12) + (lhs.a22 * rhs.a22) + (lhs.a23 * rhs.a32);
        result.a23 = (lhs.a21 * rhs.a13) + (lhs.a22 * rhs.a23) + (lhs.a23 * rhs.a33);

        result.a31 = (lhs.a31 * rhs.a11) + (lhs.a32 * rhs.a21) + (lhs.a33 * rhs.a31);
        result.a32 = (lhs.a31 * rhs.a12) + (lhs.a32 * rhs.a22) + (lhs.a33 * rhs.a32);
        result.a33 = (lhs.a31 * rhs.a13) + (lhs.a32 * rhs.a23) + (lhs.a33 * rhs.a33);

        return result;
    }

    Matrix4x4 operator*(const Matrix4x4& lhs, const Matrix4x4& rhs)
    {
        Matrix4x4 result;

        result.a11 = (lhs.a11 * rhs.a11) + (lhs.a12 * rhs.a21) + (lhs.a13 * rhs.a31) + (lhs.a14 * rhs.a41);
        result.a12 = (lhs.a11 * rhs.a12) + (lhs.a12 * rhs.a22) + (lhs.a13 * rhs.a32) + (lhs.a14 * rhs.a42);
        result.a13 = (lhs.a11 * rhs.a13) + (lhs.a12 * rhs.a23) + (lhs.a13 * rhs.a33) + (lhs.a14 * rhs.a43);
        result.a14 = (lhs.a11 * rhs.a14) + (lhs.a12 * rhs.a24) + (lhs.a13 * rhs.a34) + (lhs.a14 * rhs.a44);

        result.a21 = (lhs.a21 * rhs.a11) + (lhs.a22 * rhs.a21) + (lhs.a23 * rhs.a31) + (lhs.a24 * rhs.a41);
        result.a22 = (lhs.a21 * rhs.a12) + (lhs.a22 * rhs.a22) + (lhs.a23 * rhs.a32) + (lhs.a24 * rhs.a42);
        result.a23 = (lhs.a21 * rhs.a13) + (lhs.a22 * rhs.a23) + (lhs.a23 * rhs.a33) + (lhs.a24 * rhs.a43);
        result.a24 = (lhs.a21 * rhs.a14) + (lhs.a22 * rhs.a24) + (lhs.a23 * rhs.a34) + (lhs.a24 * rhs.a44);

        result.a31 = (lhs.a31 * rhs.a11) + (lhs.a32 * rhs.a21) + (lhs.a33 * rhs.a31) + (lhs.a14 * rhs.a41);
        result.a32 = (lhs.a31 * rhs.a12) + (lhs.a32 * rhs.a22) + (lhs.a33 * rhs.a32) + (lhs.a14 * rhs.a42);
        result.a33 = (lhs.a31 * rhs.a13) + (lhs.a32 * rhs.a23) + (lhs.a33 * rhs.a33) + (lhs.a14 * rhs.a43);
        result.a34 = (lhs.a31 * rhs.a14) + (lhs.a32 * rhs.a24) + (lhs.a33 * rhs.a34) + (lhs.a14 * rhs.a44);

        result.a41 = (lhs.a41 * rhs.a11) + (lhs.a42 * rhs.a21) + (lhs.a43 * rhs.a31) + (lhs.a44 * rhs.a41);
        result.a42 = (lhs.a41 * rhs.a12) + (lhs.a42 * rhs.a22) + (lhs.a43 * rhs.a32) + (lhs.a44 * rhs.a42);
        result.a43 = (lhs.a41 * rhs.a13) + (lhs.a42 * rhs.a23) + (lhs.a43 * rhs.a33) + (lhs.a44 * rhs.a43);
        result.a44 = (lhs.a41 * rhs.a14) + (lhs.a42 * rhs.a24) + (lhs.a43 * rhs.a34) + (lhs.a44 * rhs.a44);

        return result;
    }

    // * Matrix-vector Multiplication (Transformation of Vectors):
    Vector2f operator*(const Matrix2x2& mat, const Vector2f& vec)
    {
        Vector2f result;

        result.x = (vec.x * mat.a11) + (vec.y * mat.a12);
        result.y = (vec.x * mat.a21) + (vec.y * mat.a22);

        return result;
    }

    Vector2f operator*(const Vector2f& vec, const Matrix2x2& mat)
    {
        Vector2f result;

        result.x = (vec.x * mat.a11) + (vec.y * mat.a12);
        result.y = (vec.x * mat.a21) + (vec.y * mat.a22);

        return result;
    }


    Vector3f operator*(const Matrix3x3& mat, const Vector3f& vec)
    {
        Vector3f result;

        result.x = (vec.x * mat.a11) + (vec.y * mat.a12) + (vec.z * mat.a13);
        result.y = (vec.x * mat.a21) + (vec.y * mat.a22) + (vec.z * mat.a23);
        result.z = (vec.x * mat.a31) + (vec.y * mat.a32) + (vec.z * mat.a33);

        return result;
    }

    Vector3f operator*(const Vector3f& vec, const Matrix3x3& mat)
    {
        Vector3f result;

        result.x = (vec.x * mat.a11) + (vec.y * mat.a12) + (vec.z * mat.a13);
        result.y = (vec.x * mat.a21) + (vec.y * mat.a22) + (vec.z * mat.a23);
        result.z = (vec.x * mat.a31) + (vec.y * mat.a32) + (vec.z * mat.a33);

        return result;
    }

    Vector4f operator*(const Matrix4x4& mat, const Vector4f& vec)
    {
        Vector4f result;

        result.w = (vec.w * mat.a11) + (vec.x * mat.a12) + (vec.y * mat.a13) + (vec.z * mat.a14);
        result.x = (vec.w * mat.a21) + (vec.x * mat.a22) + (vec.y * mat.a23) + (vec.z * mat.a24);
        result.y = (vec.w * mat.a31) + (vec.x * mat.a32) + (vec.y * mat.a33) + (vec.z * mat.a34);
        result.z = (vec.w * mat.a41) + (vec.x * mat.a42) + (vec.y * mat.a43) + (vec.z * mat.a44);        

        return result;
    }

    Vector4f operator*(const Vector4f& vec, const Matrix4x4& mat)
    {
        Vector4f result;

        result.w = (vec.w * mat.a11) + (vec.x * mat.a12) + (vec.y * mat.a13) + (vec.z * mat.a14);
        result.x = (vec.w * mat.a21) + (vec.x * mat.a22) + (vec.y * mat.a23) + (vec.z * mat.a24);
        result.y = (vec.w * mat.a31) + (vec.x * mat.a32) + (vec.y * mat.a33) + (vec.z * mat.a34);
        result.z = (vec.w * mat.a41) + (vec.x * mat.a42) + (vec.y * mat.a43) + (vec.z * mat.a44);

        return result;
    }

    // * Quaternion-Quaternion Multiplication:
    Quarternian operator*(const Quarternian& lhs, const Quarternian& rhs)
    {
        Quarternian result;

        result.x = lhs.x * rhs.w +
                   lhs.y * rhs.z -
                   lhs.z * rhs.y +
                   lhs.w * rhs.x;

        result.y = -lhs.x * rhs.z +
                    lhs.y * rhs.w +
                    lhs.z * rhs.x +
                    lhs.w * rhs.y;

        result.z = lhs.x * rhs.y -
                   lhs.y * rhs.x +
                   lhs.z * rhs.w +
                   lhs.w * rhs.z;

        result.w = -lhs.x * rhs.x -
                    lhs.y * rhs.y -
                    lhs.z * rhs.z +
                    lhs.w * rhs.w;

        return result;
    }

    // * Determinant of Matrices:
    f64 DeterminantOf(const Matrix2x2& mat)
    {
        return ( (mat.a11 * mat.a22) - (mat.a21 * mat.a12) );
    }

    f64 DeterminantOf(const Matrix3x3& mat)
    {
        return
        (
             ( mat.a11 * ( (mat.a22 * mat.a33) - (mat.a32 * mat.a23) ) )
            -( mat.a12 * ( (mat.a21 * mat.a33) - (mat.a31 * mat.a23) ) )
            +( mat.a13 * ( (mat.a21 * mat.a32) - (mat.a31 * mat.a22) ) )
        );
    }

    f64 DeterminantOf(const Matrix4x4& mat)
    {
        Matrix3x3 m1 = 
		{
			mat.a22, mat.a23, mat.a24,
			mat.a32, mat.a33, mat.a34,
			mat.a42, mat.a43, mat.a44
		};

		Matrix3x3 m2 = 
		{
			mat.a21, mat.a23, mat.a24,
			mat.a31, mat.a33, mat.a34,
			mat.a41, mat.a43, mat.a44
		};

		Matrix3x3 m3 = 
		{
			mat.a21, mat.a22, mat.a24,
			mat.a31, mat.a32, mat.a34,
			mat.a41, mat.a42, mat.a44
		};

		Matrix3x3 m4 = 
		{
			mat.a21, mat.a22, mat.a23,
			mat.a31, mat.a32, mat.a33,
			mat.a41, mat.a42, mat.a43
		};

		f32 d1 = DeterminantOf(m1);
		f32 d2 = DeterminantOf(m2);
		f32 d3 = DeterminantOf(m3);
		f32 d4 = DeterminantOf(m4);

		return (
			(mat.a11 * d1) - (mat.a12 * d2) + (mat.a13 * d3) - (mat.a14 * d4)
		);
    }

    // * Inverse of Matrices:
    Matrix2x2 InverseOf(const Matrix2x2& mat)
    {
        Matrix2x2 result;

        f32 one_by_det = 1 / DeterminantOf(mat);

        f32 temp = mat.a11;

        result.a11 = one_by_det * mat.a22;
        result.a22 = one_by_det * temp;
        result.a12 = - mat.a12;
        result.a21 = - mat.a21;

        return result;
    }

    Matrix3x3 InverseOf(const Matrix3x3& mat)
    {

    }

    Matrix4x4 InverseOf(const Matrix4x4& mat)
    {

    }

    // * Transpose of Matrices:
    Matrix2x2 TransposeOf(const Matrix2x2& mat)
    {
        Matrix2x2 result;

        result.a11 = mat.a11;
        result.a12 = mat.a21;
        result.a21 = mat.a12;
        result.a22 = mat.a22;

        return result;
    }

    Matrix3x3 TransposeOf(const Matrix3x3& mat)
    {
        Matrix3x3 result;

        result.a11 = mat.a11;
        result.a12 = mat.a21;
        result.a13 = mat.a31;
        result.a21 = mat.a12;
        result.a22 = mat.a22;
        result.a23 = mat.a32;
        result.a31 = mat.a13;
        result.a32 = mat.a23;
        result.a33 = mat.a33;

        return result;
    }

    Matrix4x4 TransposeOf(const Matrix4x4& mat)
    {
        Matrix4x4 result;

        result.a11 = mat.a11;
        result.a12 = mat.a21;
        result.a13 = mat.a31;
        result.a14 = mat.a41;
        result.a21 = mat.a12;
        result.a22 = mat.a22;
        result.a23 = mat.a32;
        result.a43 = mat.a42;
        result.a31 = mat.a13;
        result.a32 = mat.a23;
        result.a33 = mat.a33;
        result.a43 = mat.a43;
        result.a41 = mat.a14;
        result.a42 = mat.a24;
        result.a43 = mat.a34;
        result.a44 = mat.a44;

        return result;
    }
}