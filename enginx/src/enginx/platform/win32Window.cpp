#include <enginx/platform/win32Window.hpp>
#include <enginx/core/graphicsContext.hpp>
#include <enginx/input/keyboard.hpp>
#include <enginx/input/mouse.hpp>
#include <enginx/utility/logger.hpp>
#include <enginx/utility/asserts.hpp>

#ifdef EX_PLATFORM_WINDOWS

namespace enginx
{
    Win32Window::Win32Window(u32 width, u32 height, const std::string& title)
        : m_width(width), m_height(height), m_defaultWindowName(title) {}
    
    Win32Window::~Win32Window()
    {

    }

    void Win32Window::OnUpdate()
    {

    }

    void Win32Window::Initialize()
    {

    }

    void Win32Window::Show() const
    {

    }

    void Win32Window::Clear() const
    {

    }

    void Win32Window::SetTitle(const std::string& title) const
    {

    }

    void Win32Window::Close()
    {

    }

    void Win32Window::PumpEvents()
    {

    }

    void Win32Window::WaitForEvents()
    {

    }

    void Win32Window::MakeContextCurrent() const
    {

    }

    void Win32Window::Present() const
    {

    }

    void Win32Window::Toggle_FullScreenMode()
    {

    }

    void Win32Window::Toggle_BorderlessMode()
    {

    }

    bool Win32Window::shouldClose() const
    {

    }

    u32 Win32Window::GetWidth() const
    {

    }

    u32 Win32Window::GetHeight() const
    {

    }

    void Win32Window::GetLocation(int& x, int& y) const
    {

    }

}

#endif