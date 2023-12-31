#include <enginx/core/window.hpp>
#include <enginx/defines.h>
#include <enginx/config.h>

#ifdef EX_PLATFORM_LINUX
    #if defined(EX_USE_XORG)
        #include <enginx/platform/X11Window.hpp>
    #elif defined(EX_USE_WAYLAND)
        #include <enginx/platform/WaylandWindow.hpp>
    #endif
#endif

#ifdef EX_PLATFORM_WINDOWS
    #include <enginx/platform/win32Window.hpp>
#endif

#ifdef EX_PLATFORM_APPLE
    #include <enginx/platform/CocoaWindow.hpp>
#endif

#include <memory>

namespace enginx
{
    std::unique_ptr<ExWindow> ExWindow::Create(u32 w, u32 h, const std::string& title)
    {
        #ifdef EX_PLATFORM_LINUX
            #if defined(EX_USE_XORG)
                return std::make_unique<X11Window>(w, h, title);
            #elif defined(EX_USE_WAYLAND)
                return std::make_unique<WaylandWindow>(w, h, title);
            #endif
        #endif

        #ifdef EX_PLATFORM_WINDOWS
            return std::make_unique<Win32Window>(w, h, title);
        #endif

        #ifdef EX_PLATFORM_APPLE
            return std::make_unique<CocoaWindow>(w, h, title);
        #endif
    }
            
}