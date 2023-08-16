#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <ex_maths/ex_maths.hpp>
#include <ex_maths/transform.hpp>

#include <enginx/event/EventListener.hpp>

namespace enginx
{
    struct PerspectiveSettings
    {
        f32 field_of_view;
        f32 aspect_ratio;
        f32 near_clip_value;
        f32 far_clip_value;                
    };
    struct OrthographicSettings
    {
        f32 left;
        f32 right;
        f32 bottom;
        f32 top;
        f32 near;
        f32 far;                
    };

    enum PROJECTION_TYPE
    {
        NOT_SET_YET = 0,
        PERSPECTIVE = 1,
        ORTHOGRAPHIC = 2,
        ISOMETRIC = 2
    };

    enum CAMERA_MOVEMENT 
    {
        CAMERA_FORWARD,
        CAMERA_BACK,
        CAMERA_LEFT,
        CAMERA_RIGHT,
        CAMERA_UP,
        CAMERA_DOWN,
    };
    class Camera : public EventListener
    {
        public:
            Camera(PROJECTION_TYPE type);
            Camera(PROJECTION_TYPE type, ex_math::Vector3f position, ex_math::Vector3f target, ex_math::Vector3f up);

            void Update(f32 dt);
            void Reset(); // * After changing any settings, reset the camera for the changes to took place.
        
        public:
            void OnKeyPress(ExKeyCode key_code) override;
            void OnKeyRelease(ExKeyCode key_code) override;
            void OnMouseMove(f32 xpos, f32 ypos) override;
        
        public:
            // ** Methods to change camera settings
            void Set_ProjectionType(PROJECTION_TYPE type);
            void Set_FOV(f32 FOV_in_degree);
            void Set_AspectRatio(f32 ratio);
            void Set_NearClip(f32 value);
            void Set_FarClip(f32 value);
        
        private:
            void CreatePrespectiveProjectionMatrix();
            void CreateOrthographicProjectionMatrix();
        
        private:
            ex_math::Matrix4x4 ProjectionMatrix;
            ex_math::Matrix4x4 ViewMatrix;
        
        private:
            // ** Camera Settings
            ex_math::Vector3f m_Position  = ex_math::Vector3f(0.0f, 0.0f, 0.0f);
            ex_math::Vector3f m_Forward   = ex_math::Vector3f(0.0f, 0.0f, -1.0f);
            ex_math::Vector3f m_Up        = ex_math::Vector3f(0.0f, 1.0f, 0.0f);
            ex_math::Vector3f m_Right     = ex_math::Vector3f(1.0f, 0.0f, 0.0f);

            PROJECTION_TYPE type_of_projection_to_use = NOT_SET_YET;

            PerspectiveSettings m_perspective_settings;
            OrthographicSettings m_orthographic_settings;

            bool is_any_of_the_settings_changed;
    };
}

#endif // CAMERA_HPP