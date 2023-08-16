#include <enginx/camera/camera.hpp>
#include <enginx/event/Event.hpp>

namespace enginx
{
    // public:

    Camera::Camera(PROJECTION_TYPE type)
    : type_of_projection_to_use(type)
    {
        if (type_of_projection_to_use == PERSPECTIVE)
        {
            CreatePrespectiveProjectionMatrix();
        }
        else if (type_of_projection_to_use == ORTHOGRAPHIC || ISOMETRIC)
        {
            CreateOrthographicProjectionMatrix();
        }

        is_any_of_the_settings_changed = false;

        EventSystem::Instance()->AddListener(this);        
    }

    Camera::Camera(PROJECTION_TYPE type, ex_math::Vector3f position, ex_math::Vector3f target, ex_math::Vector3f up) 
    : type_of_projection_to_use(type), m_Position(position), m_Forward(target), m_Up(up)
    {
        if (type_of_projection_to_use == PERSPECTIVE)
        {
            CreatePrespectiveProjectionMatrix();
        }
        else if (type_of_projection_to_use == ORTHOGRAPHIC || ISOMETRIC)
        {
            CreateOrthographicProjectionMatrix();
        }

        is_any_of_the_settings_changed = false;

        EventSystem::Instance()->AddListener(this);
    }

    void Camera::Update(f32 dt)
    {

    }
    
    void Camera::Reset()
    {
        if (is_any_of_the_settings_changed)
        {
            if (type_of_projection_to_use == PERSPECTIVE)
            {
                CreatePrespectiveProjectionMatrix(); // using the new settings
            }
            else if (type_of_projection_to_use == ORTHOGRAPHIC || ISOMETRIC)
            {
                CreateOrthographicProjectionMatrix();
            }
        }
        is_any_of_the_settings_changed = false;
    }

    void Camera::OnKeyPress(ExKeyCode key_code)
    {
        if (key_code == EX_KEY_W)
        {
            // move forward
        }

        if (key_code == EX_KEY_S)
        {
            // move backward
        }

        if (key_code == EX_KEY_A)
        {
            // move left
        }

        if (key_code == EX_KEY_D)
        {
            // move right
        }

    }

    void Camera::OnKeyRelease(ExKeyCode key_code)
    {

    }

    void Camera::OnMouseMove(f32 xpos, f32 ypos)
    {

    }

    void Camera::Set_ProjectionType(PROJECTION_TYPE type)
    {
        this->type_of_projection_to_use = type;
        is_any_of_the_settings_changed = true;
    }

    void Camera::Set_FOV(f32 FOV_in_degree)
    {
        m_perspective_settings.field_of_view = FOV_in_degree;
        is_any_of_the_settings_changed = true;
    }

    void Camera::Set_AspectRatio(f32 ratio)
    {
        m_perspective_settings.aspect_ratio = ratio;
        is_any_of_the_settings_changed = true;
    }

    void Camera::Set_NearClip(f32 value)
    {
        m_perspective_settings.near_clip_value = value;
        is_any_of_the_settings_changed = true;
    }

    void Camera::Set_FarClip(f32 value)
    {
        m_perspective_settings.far_clip_value = value;
        is_any_of_the_settings_changed = true;
    }

    // private:

    void Camera::CreatePrespectiveProjectionMatrix()
    {
        this->ProjectionMatrix = ex_math::make_perspective_matrix(
            m_perspective_settings.field_of_view,
            m_perspective_settings.aspect_ratio,
            m_perspective_settings.near_clip_value,
            m_perspective_settings.far_clip_value
        );
    }

    void Camera::CreateOrthographicProjectionMatrix()
    {
        this->ProjectionMatrix = ex_math::make_orthographic_matrix(
            m_orthographic_settings.left,
            m_orthographic_settings.right,
            m_orthographic_settings.bottom,
            m_orthographic_settings.top,
            m_orthographic_settings.near,
            m_orthographic_settings.far
        );
    }



}