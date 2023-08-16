#ifndef APPLICATION_HPP
#define APPLICATION_HPP

//#include "../core/X11_window.hpp"
#include <enginx/core/window.hpp>
#include <enginx/core/graphicsContext.hpp>
#include <enginx/event/EventListener.hpp>

#include <memory>

namespace enginx
{
    class Application : public EventListener
    {
        public:
            //Application() {}
            //virtual ~Application() {}

            //Application(const Application&) = delete;
            //Application(Application&&) = delete;
            //Application& operator=(const Application&) = delete;
            //Application& operator=(Application&&) = delete;

            virtual void Initialize();
            virtual void Release();

            void OnKeyPress(ExKeyCode key_code) override;
            void OnKeyRelease(ExKeyCode key_code) override;
            void OnMouseClick(ExMouseButtonCode mouse_button) override;
            void OnMouseRelease(ExMouseButtonCode mouse_button) override;
            void OnMouseScroll(Mouse_Scroll_direction scroll_direction) override;
            void OnMouseMove(f32 xpos, f32 ypos) override;
            void OnWindowResize(u32 new_width, u32 new_height) override;
            void OnWindowGainFocus() override;
            void OnWindowLoseFocus() override;
            void OnWindowCreate() override;
            void OnWindowClose() override;


            void Run();
            
        private:
            void Update();
        
        private:
            std::shared_ptr<ExWindow> m_window; 

    };
} // namespace enginx

#endif // ! end of APPLICATION_HPP