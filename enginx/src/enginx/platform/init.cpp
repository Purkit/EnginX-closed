#include <enginx/platform/init.hpp>

namespace enginx
{
    void Platform::StartUp()
    {
        XConnection::Connect();
        XScreen::GetDefaultScreen();
        //Keyboard::Disable_AutoKeyRepeat();
    }

    void Platform::ShutDown()
    {
        //Keyboard::Enable_AutoKeyRepeat();
        XConnection::Disconnect();
    }
}