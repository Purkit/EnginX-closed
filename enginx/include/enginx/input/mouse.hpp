#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <memory.h>

#include "../defines.h"

namespace enginx
{
    // TODO: Move this Point struct to some math header.
    struct Point
    {
        f32 x;
        f32 y;
    };

    enum ExMouseButtonCode
    {
        EX_LEFT_MOUSE_BUTTON    =   1,
        EX_MIDDLE_MOUSE_BUTTON  =   2,
        EX_RIGHT_MOUSE_BUTTON   =   3
    };

    enum Mouse_State
    {
        EX_MOUSE_BUTTON_NONE  =   0,
        EX_MOUSE_BUTTON_PRESSED  =   1,
        EX_MOUSE_BUTTON_RELEASED  =   2
    };

    enum Mouse_Scroll_direction
    {
        EX_MOUSE_SCROLL_UP,
        EX_MOUSE_SCROLL_DOWN
    };

    class EXAPI Mouse
    {
        private:
            static unsigned char m_MouseState[3];
            static Point m_MousePosition;
        
        public:
            static void UpdateState(ExMouseButtonCode button_name, Mouse_State button_state);
            static void UpdatePosition(f32 xpos, f32 ypos);
            static void Reset();

            static bool isMouseButtonPressed(ExMouseButtonCode button_name);
            static bool isMouseButtonReleased(ExMouseButtonCode button_name);

            static void getMousePosition(f32& xpos, f32& ypos);
            static void getMousePosition(Point& point);

    };
}

#endif // ! end of MOUSE_HPP