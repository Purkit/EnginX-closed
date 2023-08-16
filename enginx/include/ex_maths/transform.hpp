#ifndef TRANSFORMS_HPP
#define TRANSFORMS_HPP

#include <ex_maths/vector.hpp>
#include <ex_maths/matrix.hpp>
#include <ex_maths/operations.hpp>

namespace ex_math
{
    Matrix4x4 make_lookat_matrix(Vector3f eye_position, Vector3f eye_target, Vector3f up_vector);
    
    Matrix4x4 make_translational_matrix(Vector3f position);
    Matrix4x4 make_scaling_matrix(Vector3f scaling_factor);

    Matrix4x4 make_euler_rotation_matrix_x(f32 angle_in_rad);
    Matrix4x4 make_euler_rotation_matrix_y(f32 angle_in_rad);
    Matrix4x4 make_euler_rotation_matrix_z(f32 angle_in_rad);
    Matrix4x4 make_euler_rotation_matrix_xyz(f32 x_radians, f32 y_radians, f32 z_radians);

    Quarternian make_quaternion_from_euler_angle(Vector3f axis, f32 angle);
    Quarternian make_quaternion_from_to_vector(Vector3f from, Vector3f to); // ? is it required ?
    Quarternian quaternion_slerp(Quarternian q_0, Quarternian q_1, f32 percentage);

    Matrix4x4 make_rotation_matrix_from_quaternion(Quarternian q);
    Matrix4x4 make_rotation_matrix_from_quaternion(Quarternian q, Vector3f center);

    Matrix4x4 make_perspective_matrix(f32 fov, f32 aspect_ratio, f32 znear, f32 zfar);
    Matrix4x4 make_orthographic_matrix(f32 left, f32 right, f32 buttom, f32 top, f32 znear, f32 zfar);
}

#endif