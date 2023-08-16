#ifndef LAYERS_HPP
#define LAYERS_HPP

#include <iostream>
#include <enginx/event/Event.hpp> // cause we need key code enum.
#include <enginx/defines.h>

namespace enginx
{
    class Layer
    {        
        public:
            Layer(const u8 LayerID = 0);
            virtual ~Layer();

            virtual void OnEnable() {}
            virtual void OnDisable() {}
            virtual void Update() {}

            virtual void OnKeyPress(ExKeyCode key_code) {}
            virtual void OnKeyRelease(ExKeyCode key_code) {}
            virtual void OnMouseClick(ExMouseButtonCode mouse_button) {}
            virtual void OnMouseRelease(ExMouseButtonCode mouse_button) {}
            virtual void OnMouseScroll(Mouse_Scroll_direction scroll_direction) {}
            virtual void OnMouseMove(f32 xpos, f32 ypos) {}
            virtual void OnWindowResize(u32 new_width, u32 new_height) {}
            virtual void OnWindowGainFocus() {}
            virtual void OnWindowLoseFocus() {}
            virtual void OnWindowCreate() {}
            virtual void OnWindowClose() {}
        
        protected:
            u8 m_LayerID;
    };
    
}

#endif // LAYERS_HPP