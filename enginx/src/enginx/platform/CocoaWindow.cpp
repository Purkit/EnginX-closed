#include <enginx/platform/CocoaWindow.hpp>
#include <enginx/core/graphicsContext.hpp>
#include <enginx/input/keyboard.hpp>
#include <enginx/input/mouse.hpp>
#include <enginx/utility/logger.hpp>
#include <enginx/utility/asserts.hpp>

#ifdef EX_PLATFORM_APPLE

namespace enginx
{
    CocoaWindow::CocoaWindow(u32 width, u32 height, const std::string& title)
        : m_width(width), m_height(height), m_defaultWindowName(title) {}
    
    CocoaWindow::~CocoaWindow()
    {

    }

    void CocoaWindow::OnUpdate()
    {

    }

    void CocoaWindow::Initialize()
    {

    }

    void CocoaWindow::Show() const
    {

    }

    void CocoaWindow::Clear() const
    {

    }

    void CocoaWindow::SetTitle(const std::string& title) const
    {

    }

    void CocoaWindow::Close()
    {

    }

    void CocoaWindow::PumpEvents()
    {

    }

    void CocoaWindow::WaitForEvents()
    {

    }

    void CocoaWindow::MakeContextCurrent() const
    {

    }

    void CocoaWindow::Present() const
    {

    }

    void CocoaWindow::Toggle_FullScreenMode()
    {

    }

    void CocoaWindow::Toggle_BorderlessMode()
    {

    }

    bool CocoaWindow::shouldClose() const
    {

    }

    u32 CocoaWindow::GetWidth() const
    {

    }

    u32 CocoaWindow::GetHeight() const
    {

    }

    void CocoaWindow::GetLocation(int& x, int& y) const
    {

    }

}

#endif