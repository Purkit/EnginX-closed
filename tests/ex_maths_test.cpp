#include <iostream>
#include <ex_maths/ex_maths.hpp>

int main()
{
    ex_math::Vector3f vec_1(1.0f, 2.0f, 3.0f);
    ex_math::Vector3f vec_2(19.0f, 24.0f, 13.0f);
    ex_math::Vector3f vec_res = vec_1 + vec_2;

    std::cout << "Vector 1 :" << "\t" << vec_1.x << "\t" << vec_1.y << "\t" << vec_1.z << "\n";
    std::cout << "Vector 2 :" << "\t" << vec_2.x << "\t" << vec_2.y << "\t" << vec_2.z << "\n";
    std::cout << "On Adding:" << "\t" << vec_res.x << "\t" << vec_res.y << "\t" << vec_res.z << " <--- Vector 3\n";

    ex_math::Vector3f vec_res_normalized = vec_res.Normalized();
    std::cout << "Normalized version of Vector 3:\n";
    std::cout << vec_res_normalized.x << "\t" << vec_res_normalized.y << "\t" << vec_res_normalized.z << "\n";

    std::cout << "Length of Vector 3 = " << vec_res.Length() << "\n";
    std::cout << "Length of Normalized version of Vector 3 = " << vec_res_normalized.Length() << "\n";

    ex_math::Matrix3x3 mat;
    mat.MakeIdentity();
    std::cout << mat.Determinant() << "\n";

    return 0;
}