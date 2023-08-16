#ifndef WIN32_WINDOW_HPP
#define WIN32_WINDOW_HPP

#include "../defines.h"

#ifdef EX_PLATFORM_WINDOWS

#include "../core/window.hpp"

// include windows/win32 headers here

namespace enginx
{
    class Win32Window : public ExWindow
    {
        public:
            Win32Window(u32 width, u32 height, const std::string& title);
            //Win32Window(const ExWindowConfigInfo& window_configuration);
            virtual ~Win32Window();
        
        public:
            void OnUpdate() override;

            void Initialize() override;
            
            void Show() const override;
            void Clear() const override;
            void SetTitle(const std::string& title) const override;
            void Close() override;

            void PumpEvents() override;      // * Non blocking
            void WaitForEvents() override;   // * Blocking

            void MakeContextCurrent() const override;
            void Present() const override;

            void Toggle_FullScreenMode() override;
            void Toggle_BorderlessMode() override;

            bool shouldClose() const override;

            u32 GetWidth() const override;
            u32 GetHeight() const override;
            void GetLocation(int& x, int& y) const override;
        
        private:
            const u32 m_width;
            const u32 m_height;
            std::string m_defaultWindowName;
            bool m_shouldClose = false;

            bool borderless = false;
            bool fullscreen = false;
    };
}

#endif // EX_PLATFORM_WINDOWS

#endif // WIN32_WINDOW_HPP