#include <ex_maths/transform.hpp>
#include <math.h>

namespace ex_math
{
    Matrix4x4 make_lookat_matrix(Vector3f eye_position, Vector3f eye_target, Vector3f up_vector)
    {
        Matrix4x4 lookat_matrix;

        Vector3f z_axis;
        z_axis.x = eye_target.x - eye_position.x;
        z_axis.y = eye_target.y - eye_position.y;
        z_axis.z = eye_target.z - eye_position.z;
        z_axis.Normalize();

        Vector3f x_axis = Cross(z_axis, up_vector);
        x_axis.Normalize();

        Vector3f y_axis = Cross(x_axis, z_axis);

        lookat_matrix.a11 = x_axis.x;
        lookat_matrix.a21 = y_axis.x;
        lookat_matrix.a31 = -z_axis.x;
        lookat_matrix.a41 = 0;
        lookat_matrix.a12 = x_axis.y;
        lookat_matrix.a22 = y_axis.y;
        lookat_matrix.a32 = -z_axis.y;
        lookat_matrix.a42 = 0;
        lookat_matrix.a13 = x_axis.z;
        lookat_matrix.a23 = y_axis.z;
        lookat_matrix.a33 = -z_axis.z;
        lookat_matrix.a43 = 0;
        lookat_matrix.a14 = -Dot(x_axis, eye_position);
        lookat_matrix.a24 = Dot(y_axis, eye_position);
        lookat_matrix.a34 = -Dot(z_axis, eye_position);
        lookat_matrix.a44 = 1.0f;

        return lookat_matrix;
    }

    Matrix4x4 make_translational_matrix(Vector3f position)
    {
        Matrix4x4 translation_matrix(0);
        translation_matrix.MakeIdentity();

        translation_matrix.a14 = position.x;
        translation_matrix.a24 = position.y;
        translation_matrix.a34 = position.z;

        return translation_matrix;
    }

    Matrix4x4 make_scaling_matrix(Vector3f scaling_factor)
    {
        Matrix4x4 scaling_matrix(0);
        scaling_matrix.MakeIdentity();

        scaling_matrix.a11 = scaling_factor.x;
        scaling_matrix.a22 = scaling_factor.y;
        scaling_matrix.a33 = scaling_factor.z;

        return scaling_matrix;
    }

    Matrix4x4 make_euler_rotation_matrix_x(f32 angle_in_rad)
    {
        Matrix4x4 rotational_matrix_along_x(0);
        rotational_matrix_along_x.MakeIdentity();

        f32 c = cos(angle_in_rad);
        f32 s = sin(angle_in_rad);

        rotational_matrix_along_x.a22 = c;
        rotational_matrix_along_x.a32 = s;
        rotational_matrix_along_x.a23 = -s;
        rotational_matrix_along_x.a33 = c;

        return rotational_matrix_along_x;
    }

    Matrix4x4 make_euler_rotation_matrix_y(f32 angle_in_rad)
    {
        Matrix4x4 rotational_matrix_along_y(0);
        rotational_matrix_along_y.MakeIdentity();

        f32 c = cos(angle_in_rad);
        f32 s = sin(angle_in_rad);

        rotational_matrix_along_y.a11 = c;
        rotational_matrix_along_y.a31 = -s;
        rotational_matrix_along_y.a13 = s;
        rotational_matrix_along_y.a33 = c;        

        return rotational_matrix_along_y;
    }

    Matrix4x4 make_euler_rotation_matrix_z(f32 angle_in_rad)
    {
        Matrix4x4 rotational_matrix_along_z(0);
        rotational_matrix_along_z.MakeIdentity();

        f32 c = cos(angle_in_rad);
        f32 s = sin(angle_in_rad);

        rotational_matrix_along_z.a11 = c;
        rotational_matrix_along_z.a21 = s;
        rotational_matrix_along_z.a12 = -s;
        rotational_matrix_along_z.a22 = c;

        return rotational_matrix_along_z;
    }

    Matrix4x4 make_euler_rotation_matrix_xyz(f32 x_radians, f32 y_radians, f32 z_radians)
    {
        Matrix4x4 rotational_matrix_along_x = make_euler_rotation_matrix_x(x_radians);
        Matrix4x4 rotational_matrix_along_y = make_euler_rotation_matrix_y(y_radians);
        Matrix4x4 rotational_matrix_along_z = make_euler_rotation_matrix_z(z_radians);
        Matrix4x4 resultant_matrix = rotational_matrix_along_x * rotational_matrix_along_y;
        resultant_matrix = resultant_matrix * rotational_matrix_along_z;
        return resultant_matrix;
    }

    Quarternian make_quaternion_from_euler_angle(Vector3f axis, f32 angle)
    {
        const f32 half_angle = 0.5f * angle;
        f32 s = sin(half_angle);
        f32 c = cos(half_angle);

        Quarternian q = (Quarternian){s * axis.x, s * axis.y, s * axis.z, c};
        q.Normalize();

        return q;
    }

    Quarternian make_quaternion_from_to_vector(Vector3f from, Vector3f to)
    {
        Quarternian q;
        Vector3f axis = Cross(from, to);
        axis.Normalize();

        q.w = sqrt( from.LengthSqr() * to.LengthSqr() ) + Dot(from, to);
        q.x = axis.x;
        q.y = axis.y;
        q.z = axis.z;

        return q;
    }

    Quarternian quaternion_slerp(Quarternian q_0, Quarternian q_1, f32 percentage)
    {
        Quarternian out_quaternion;
        // Source: https://en.wikipedia.org/wiki/Slerp
        // Only unit quaternions are valid rotations.
        // Normalize to avoid undefined behavior.
        Quarternian v0 = q_0.Normalized();
        Quarternian v1 = q_1.Normalized();

        // Compute the cosine of the angle between the two vectors.
        f32 dot = Dot(v0, v1);

        // If the dot product is negative, slerp won't take
        // the shorter path. Note that v1 and -v1 are equivalent when
        // the negation is applied to all four components. Fix by
        // reversing one quaternion.
        if (dot < 0.0f)
        {
            v1.x = -v1.x;
            v1.y = -v1.y;
            v1.z = -v1.z;
            v1.w = -v1.w;
            dot = -dot;
        }

        const f32 DOT_THRESHOLD = 0.9995f;
        if (dot > DOT_THRESHOLD)
        {
            // If the inputs are too close for comfort, linearly interpolate
            // and normalize the result.
            out_quaternion = 
            (Quarternian)
            {
                v0.x + ((v1.x - v0.x) * percentage),
                v0.y + ((v1.y - v0.y) * percentage),
                v0.z + ((v1.z - v0.z) * percentage),
                v0.w + ((v1.w - v0.w) * percentage)
            };
            out_quaternion.Normalize();

            return out_quaternion;
        }

        // Since dot is in range [0, DOT_THRESHOLD], acos is safe
        f32 theta_0 = acos(dot);          // theta_0 = angle between input vectors
        f32 theta = theta_0 * percentage;  // theta = angle between v0 and result
        f32 sin_theta = sin(theta);       // compute this value only once
        f32 sin_theta_0 = sin(theta_0);   // compute this value only once

        f32 s0 = cos(theta) - dot * sin_theta / sin_theta_0;  // == sin(theta_0 - theta) / sin(theta_0)
        f32 s1 = sin_theta / sin_theta_0;

        return (Quarternian){
            (v0.x * s0) + (v1.x * s1),
            (v0.y * s0) + (v1.y * s1),
            (v0.z * s0) + (v1.z * s1),
            (v0.w * s0) + (v1.w * s1)};
    }

    Matrix4x4 make_rotation_matrix_from_quaternion(Quarternian q)
    {
        Matrix4x4 rotation_matrix(0);
        rotation_matrix.MakeIdentity();
    
        q.Normalize();

        rotation_matrix.a11 = 1.0f - 2.0f * q.y * q.y - 2.0f * q.z * q.z;
        rotation_matrix.a21 = 2.0f * q.x * q.y - 2.0f * q.z * q.w;
        rotation_matrix.a31 = 2.0f * q.x * q.z + 2.0f * q.y * q.w;

        rotation_matrix.a12 = 2.0f * q.x * q.y + 2.0f * q.z * q.w;
        rotation_matrix.a22 = 1.0f - 2.0f * q.x * q.x - 2.0f * q.z * q.z;
        rotation_matrix.a32 = 2.0f * q.y * q.z - 2.0f * q.x * q.w;

        rotation_matrix.a13 = 2.0f * q.x * q.z - 2.0f * q.y * q.w;
        rotation_matrix.a23 = 2.0f * q.y * q.z + 2.0f * q.x * q.w;
        rotation_matrix.a33 = 1.0f - 2.0f * q.x * q.x - 2.0f * q.y * q.y;

        return rotation_matrix;
    }

    Matrix4x4 make_rotation_matrix_from_quaternion(Quarternian q, Vector3f center)
    {
        Matrix4x4 rotation_matrix(0);

        rotation_matrix.a11 = (q.x * q.x) - (q.y * q.y) - (q.z * q.z) + (q.w * q.w);
        rotation_matrix.a21 = 2.0f * ((q.x * q.y) + (q.z * q.w));
        rotation_matrix.a31 = 2.0f * ((q.x * q.z) - (q.y * q.w));
        rotation_matrix.a41 = center.x - center.x * rotation_matrix.a11 - center.y * rotation_matrix.a21 - center.z * rotation_matrix.a31;

        rotation_matrix.a12 = 2.0f * ((q.x * q.y) - (q.z * q.w));
        rotation_matrix.a22 = -(q.x * q.x) + (q.y * q.y) - (q.z * q.z) + (q.w * q.w);
        rotation_matrix.a32 = 2.0f * ((q.y * q.z) + (q.x * q.w));
        rotation_matrix.a42 = center.y - center.x * rotation_matrix.a12 - center.y * rotation_matrix.a22 - center.z * rotation_matrix.a32;

        rotation_matrix.a13 = 2.0f * ((q.x * q.z) + (q.y * q.w));
        rotation_matrix.a23 = 2.0f * ((q.y * q.z) - (q.x * q.w));
        rotation_matrix.a33 = -(q.x * q.x) - (q.y * q.y) + (q.z * q.z) + (q.w * q.w);
        rotation_matrix.a43 = center.z - center.x * rotation_matrix.a13 - center.y * rotation_matrix.a23 - center.z * rotation_matrix.a33;

        rotation_matrix.a14 = 0.0f;
        rotation_matrix.a24 = 0.0f;
        rotation_matrix.a34 = 0.0f;
        rotation_matrix.a44 = 1.0f;

        return rotation_matrix;
    }

    Matrix4x4 make_perspective_matrix(f32 fov, f32 aspect_ratio, f32 znear, f32 zfar)
    {
        Matrix4x4 perspective_matrix(0);
        
        perspective_matrix.a11 = aspect_ratio * (1 / tan(fov/2));
        perspective_matrix.a22 = 1 / tan(fov/2);
        perspective_matrix.a33 = zfar / (zfar - znear);
        perspective_matrix.a34 = (-zfar * znear) / (zfar - znear);
        perspective_matrix.a43 = 1.0f;

        return perspective_matrix;
    }

    Matrix4x4 make_orthographic_matrix(f32 left, f32 right, f32 bottom, f32 top, f32 znear, f32 zfar)
    {
        Matrix4x4 orthographic_matrix(0);

        orthographic_matrix.a11 = 2.0f / (right - left);
        orthographic_matrix.a22 = 2.0f / (top - bottom);
        orthographic_matrix.a33 = 2.0f / (zfar - znear);
        orthographic_matrix.a44 = 1.0f;
        orthographic_matrix.a14 = -(right + left) / (right - left);
        orthographic_matrix.a24 = -(bottom + top) / (bottom - top);
        orthographic_matrix.a34 = -(znear + zfar) / (zfar - znear);

        return orthographic_matrix;
    }
}