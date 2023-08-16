#include <ex_maths/matrix.hpp>
#include <ex_maths/operations.hpp>
#include <ex_maths/utility.hpp>

namespace ex_math
{

	// * //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// * //
    // * ---------------------------------- MATRIX IMPLEMENTATION FOR TRADITIONAL MATH LIBRARY ---------------------------------- * //
    // * //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// * //

    // * 2x2 Matrix
    Matrix2x2::Matrix2x2()
    : a11(0), a12(0),
      a21(0), a22(0) 
    {}
    
    Matrix2x2::Matrix2x2(f32 _i)
    : a11(_i), a12(_i),
      a21(_i), a22(_i)
    {}
    
    Matrix2x2::Matrix2x2
    (
        f32 _i11, f32 _i12,
        f32 _i21, f32 _i22
    )
    : a11(_i11), a12(_i12),
      a21(_i21), a22(_i22)
    {}

    void Matrix2x2::MakeIdentity()
    {
		a11 = a22 = 1;
		a12 = a21 = 0;
    }

	void Matrix2x2::Transpose()
	{
		f32 temp = this->a21;
		this->a21 = this->a12;
		this->a12 = temp;
	}

	void Matrix2x2::Inverse()
	{
		Swap(this->a11, this->a22);
		a12 = -a12;
		a21 = -a21;

		f32 one_by_det = 1 / DeterminantOf(*this);

		a11 = one_by_det * a11;
		a12 = one_by_det * a12;
		a21 = one_by_det * a21;
		a22 = one_by_det * a22;
	}

    f32 Matrix2x2::Determinant() const
    {
        return ( (this->a11 * this->a22) - (this->a21 * this->a12) );
    }

    void Matrix2x2::operator=(const std::array<f32, 4>&& data)
    {
        this->a11 = data[0];    this->a12 = data[1];
        this->a21 = data[2];    this->a22 = data[3];
    }

	Matrix2x2 Matrix2x2::operator+(const Matrix2x2& to_add) const
	{
		Matrix2x2 result;

		result.a11 = this->a11 + to_add.a11;
		result.a12 = this->a12 + to_add.a12;
		result.a21 = this->a21 + to_add.a21;
		result.a22 = this->a22 + to_add.a22;

		return result;
	}

	Matrix2x2 operator*(const f32& scalar, const Matrix2x2& matrix_to_scale)
	{
		Matrix2x2 result;

		result.a11 = matrix_to_scale.a11 * scalar;
		result.a12 = matrix_to_scale.a12 * scalar;
		result.a21 = matrix_to_scale.a21 * scalar;
		result.a22 = matrix_to_scale.a22 * scalar;

		return result;		
	}	

    // * 3x3 Matrix
    Matrix3x3::Matrix3x3()
    : a11(0), a12(0), a13(0),
      a21(0), a22(0), a23(0),
      a31(0), a32(0), a33(0)
    {}

    Matrix3x3::Matrix3x3(f32 _i)
    : a11(_i), a12(_i), a13(_i),
      a21(_i), a22(_i), a23(_i),
      a31(_i), a32(_i), a33(_i)
    {}

    Matrix3x3::Matrix3x3
    (
        f32 _i11, f32 _i12, f32 _i13,
        f32 _i21, f32 _i22, f32 _i23,
        f32 _i31, f32 _i32, f32 _i33
    )
    : a11(_i11), a12(_i12), a13(_i13),
      a21(_i21), a22(_i22), a23(_i23),
      a31(_i31), a32(_i32), a33(_i33)
    {}

	void Matrix3x3::MakeIdentity()
	{
		a11 = a22 = a33 = 1;
		a12 = a13 = a21 = a23 = a31 = a32 = 0;
	}

	void Matrix3x3::Transpose()
	{
		Swap(this->a12, this->a21);
		Swap(this->a13, this->a31);
		Swap(this->a23, this->a32);
	}

	void Matrix3x3::Inverse()
	{

	}

    f32 Matrix3x3::Determinant() const
    {
        return
        (
             ( this->a11 * ( (this->a22 * this->a33) - (this->a32 * this->a23) ) )
            -( this->a12 * ( (this->a21 * this->a33) - (this->a31 * this->a23) ) )
            +( this->a13 * ( (this->a21 * this->a32) - (this->a31 * this->a22) ) )
        );
    }

    void Matrix3x3::operator=(const std::array<f32, 9>&& data)
    {
        this->a11 = data[0];    this->a12 = data[1];    this->a13 = data[2];
        this->a21 = data[3];    this->a22 = data[4];    this->a23 = data[5];
        this->a31 = data[6];    this->a32 = data[7];    this->a33 = data[8];
    }

	Matrix3x3 Matrix3x3::operator+(const Matrix3x3& to_add) const
	{
		Matrix3x3 result;

		result.a11 = this->a11 + to_add.a11;
		result.a12 = this->a12 + to_add.a12;
		result.a13 = this->a13 + to_add.a13;
		result.a21 = this->a21 + to_add.a21;
		result.a22 = this->a22 + to_add.a22;
		result.a23 = this->a23 + to_add.a23;
		result.a31 = this->a31 + to_add.a31;
		result.a32 = this->a32 + to_add.a32;
		result.a33 = this->a33 + to_add.a33;

		return result;
	}

	Matrix3x3 operator*(const f32& scalar, const Matrix3x3& matrix_to_scale)
	{
		Matrix3x3 result;

		result.a11 = matrix_to_scale.a11 * scalar;
		result.a12 = matrix_to_scale.a12 * scalar;
		result.a13 = matrix_to_scale.a13 * scalar;
		result.a21 = matrix_to_scale.a21 * scalar;
		result.a22 = matrix_to_scale.a22 * scalar;
		result.a23 = matrix_to_scale.a23 * scalar;
		result.a31 = matrix_to_scale.a31 * scalar;
		result.a32 = matrix_to_scale.a32 * scalar;
		result.a33 = matrix_to_scale.a33 * scalar;

		return result;
	}

    // * 4x4 Matrix
    Matrix4x4::Matrix4x4()
    : a11(0), a12(0), a13(0), a14(0),
      a21(0), a22(0), a23(0), a24(0),
      a31(0), a32(0), a33(0), a34(0),
      a41(0), a42(0), a43(0), a44(0)
    {}

    Matrix4x4::Matrix4x4(f32 _i)
    : a11(_i), a12(_i), a13(_i), a14(_i),
      a21(_i), a22(_i), a23(_i), a24(_i),
      a31(_i), a32(_i), a33(_i), a34(_i),
      a41(_i), a42(_i), a43(_i), a44(_i)
    {}

    Matrix4x4::Matrix4x4
    (
        f32 _i11, f32 _i12, f32 _i13, f32 _i14,
        f32 _i21, f32 _i22, f32 _i23, f32 _i24,
        f32 _i31, f32 _i32, f32 _i33, f32 _i34,
        f32 _i41, f32 _i42, f32 _i43, f32 _i44
    )
    : a11(_i11), a12(_i12), a13(_i13), a14(_i14),
      a21(_i21), a22(_i22), a23(_i23), a24(_i24),
      a31(_i31), a32(_i32), a33(_i33), a34(_i34),
      a41(_i41), a42(_i42), a43(_i43), a44(_i44)
    {}

	void Matrix4x4::MakeIdentity()
	{
		a11 = a22 = a33 = a44 = 1;
		a12 = a13 = a14 = a21 = a23 = a24 = a31 = a32 = a34 = a41 = a42 = a43 = 0;
	}

	void Matrix4x4::Transpose()
	{
		Swap(this->a12, this->a21);
		Swap(this->a13, this->a31);
		Swap(this->a14, this->a41);
		Swap(this->a23, this->a32);
		Swap(this->a24, this->a42);
		Swap(this->a34, this->a43);
	}

	void Matrix4x4::Inverse()
	{

	}

	f32 Matrix4x4::Determinant() const
	{
		Matrix3x3 m1 = 
		{
			a22, a23, a24,
			a32, a33, a34,
			a42, a43, a44
		};

		Matrix3x3 m2 = 
		{
			a21, a23, a24,
			a31, a33, a34,
			a41, a43, a44
		};

		Matrix3x3 m3 = 
		{
			a21, a22, a24,
			a31, a32, a34,
			a41, a42, a44
		};

		Matrix3x3 m4 = 
		{
			a21, a22, a23,
			a31, a32, a33,
			a41, a42, a43
		};

		f32 d1 = DeterminantOf(m1);
		f32 d2 = DeterminantOf(m2);
		f32 d3 = DeterminantOf(m3);
		f32 d4 = DeterminantOf(m4);

		return (
			(a11 * d1) - (a12 * d2) + (a13 * d3) - (a14 * d4)
		);
	}

    void Matrix4x4::operator=(const std::array<f32, 16>&& data)
    {
        this->a11 = data[0];    this->a12 = data[1];    this->a13 = data[2];    this->a14 = data[3];
        this->a21 = data[4];    this->a22 = data[5];    this->a23 = data[6];    this->a24 = data[7];
        this->a31 = data[8];    this->a32 = data[9];    this->a33 = data[10];   this->a34 = data[11];
        this->a41 = data[12];   this->a42 = data[13];   this->a43 = data[14];   this->a44 = data[15];
    }

	Matrix4x4 Matrix4x4::operator+(const Matrix4x4& to_add) const
	{
		Matrix4x4 result;

		result.a11 = this->a11 + to_add.a11;
		result.a12 = this->a12 + to_add.a12;
		result.a13 = this->a13 + to_add.a13;
		result.a14 = this->a14 + to_add.a14;
		result.a21 = this->a21 + to_add.a21;
		result.a22 = this->a22 + to_add.a22;
		result.a23 = this->a23 + to_add.a23;
		result.a24 = this->a24 + to_add.a24;
		result.a31 = this->a31 + to_add.a31;
		result.a32 = this->a32 + to_add.a32;
		result.a33 = this->a33 + to_add.a33;
		result.a34 = this->a34 + to_add.a34;
		result.a41 = this->a41 + to_add.a41;
		result.a42 = this->a42 + to_add.a42;
		result.a43 = this->a43 + to_add.a43;
		result.a44 = this->a44 + to_add.a44;

		return result;
	}

	Matrix4x4 operator*(const f32& scalar, const Matrix4x4& matrix_to_scale)
	{
		Matrix4x4 result;

		result.a11 = matrix_to_scale.a11 * scalar;
		result.a12 = matrix_to_scale.a12 * scalar;
		result.a13 = matrix_to_scale.a13 * scalar;
		result.a14 = matrix_to_scale.a14 * scalar;
		result.a21 = matrix_to_scale.a21 * scalar;
		result.a22 = matrix_to_scale.a22 * scalar;
		result.a23 = matrix_to_scale.a23 * scalar;
		result.a24 = matrix_to_scale.a24 * scalar;
		result.a31 = matrix_to_scale.a31 * scalar;
		result.a32 = matrix_to_scale.a32 * scalar;
		result.a33 = matrix_to_scale.a33 * scalar;
		result.a34 = matrix_to_scale.a34 * scalar;
		result.a41 = matrix_to_scale.a41 * scalar;
		result.a42 = matrix_to_scale.a42 * scalar;
		result.a43 = matrix_to_scale.a43 * scalar;
		result.a44 = matrix_to_scale.a44 * scalar;

		return result;
	}

	// * //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// * //
    // * -------------------------------- MATRIX IMPLEMENTATION FOR SIMD ACCLERATED MATH LIBRARY -------------------------------- * //
    // * //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// * //


}