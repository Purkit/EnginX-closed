#ifndef EVENT_LISTENER_HPP
#define EVENT_LISTENER_HPP

#include "../defines.h"
#include "../input/keyboard.hpp"
#include "../input/mouse.hpp"

namespace enginx
{
    
    class EventListener
    {
        public:
            virtual void OnKeyPress(ExKeyCode key_code) = 0;
            virtual void OnKeyRelease(ExKeyCode key_code) = 0;
            virtual void OnMouseClick(ExMouseButtonCode mouse_button) = 0;
            virtual void OnMouseRelease(ExMouseButtonCode mouse_button) = 0;
            virtual void OnMouseScroll(Mouse_Scroll_direction scroll_direction) = 0;
            virtual void OnMouseMove(f32 xpos, f32 ypos) = 0;            
            virtual void OnWindowResize(u32 new_width, u32 new_height) = 0;
            virtual void OnWindowGainFocus() = 0;
            virtual void OnWindowLoseFocus() = 0;
            virtual void OnWindowCreate() = 0;
            virtual void OnWindowClose() = 0;
    };

}

#endif // EVENT_LISTENER_HPP