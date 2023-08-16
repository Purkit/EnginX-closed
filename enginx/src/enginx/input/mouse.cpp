#include <enginx/input/mouse.hpp>

namespace enginx
{
    unsigned char Mouse::m_MouseState[3] = {};
    Point Mouse::m_MousePosition = {};

    void Mouse::UpdateState(ExMouseButtonCode button_name, Mouse_State button_state)
    {
        m_MouseState[button_name] = button_state;        
    }

    void Mouse::UpdatePosition(f32 xpos, f32 ypos)
    {
        m_MousePosition.x = xpos;
        m_MousePosition.y = ypos;     
    }

    void Mouse::Reset()
    {
        memset(m_MouseState, 0, sizeof(unsigned char)*3);
    }

    bool Mouse::isMouseButtonPressed(ExMouseButtonCode button_name)
    {
        return m_MouseState[button_name] == EX_MOUSE_BUTTON_PRESSED;        
    }

    bool Mouse::isMouseButtonReleased(ExMouseButtonCode button_name)
    {
        return m_MouseState[button_name] == EX_MOUSE_BUTTON_RELEASED;
    }

    void Mouse::getMousePosition(f32& xpos, f32& ypos)
    {
        xpos = m_MousePosition.x;
        ypos = m_MousePosition.y;
    }

    void Mouse::getMousePosition(Point& point)
    {
        point.x = m_MousePosition.x;
        point.y = m_MousePosition.y;        
    }

}