#include <enginx/platform/WaylandWindow.hpp>

#ifdef EX_USE_WAYLAND

// include wayland headers here

namespace enginx
{
    WaylandWindow::WaylandWindow(u32 width, u32 height, const std::string& title)
        : m_width(width), m_height(height), m_defaultWindowName(title)
    {}

    WaylandWindow::WaylandWindow(const ExWindowConfigInfo& window_configuration)
        : m_width(window_configuration.Width),
          m_height(window_configuration.Height),
          m_defaultWindowName(window_configuration.Title)
    {}

    WaylandWindow::~WaylandWindow()
    {

    }

    void WaylandWindow::OnUpdate()
    {

    }

    void WaylandWindow::Create()
    {

    }

    void WaylandWindow::Show() const
    {

    }

    void WaylandWindow::Clear() const
    {

    }

    void WaylandWindow::SetTitle(std::string& title) const
    {

    }

    void WaylandWindow::Close()
    {

    }

    void WaylandWindow::PumpEvents()
    {

    }

    void WaylandWindow::WaitForEvents()
    {

    }

    void WaylandWindow::MakeContextCurrent() const
    {

    }

    void WaylandWindow::Present() const
    {

    }

    void WaylandWindow::Toggle_FullScreenMode()
    {

    }

    void WaylandWindow::Toggle_BorderlessMode()
    {

    }

    bool WaylandWindow::shouldClose() const
    {

    }

    u32 WaylandWindow::GetWidth() const
    {

    }

    u32 WaylandWindow::GetHeight() const
    {

    }

    void WaylandWindow::GetLocation(int& x, int& y) const
    {
        
    }
}

#endif // EX_USE_WAYLAND