#include <enginx/core/screen.hpp>
#include <enginx/core/connection.hpp>

Screen* XScreen::defaultScreen = NULL;
int XScreen::defaultScreen_ID = {};

void XScreen::GetDefaultScreen()
{
    defaultScreen = DefaultScreenOfDisplay(XConnection::connection);
    defaultScreen_ID = DefaultScreen(XConnection::connection);
}

void XScreen::Release()
{

}

int XScreen::GetWidth()
{
    return defaultScreen->width;
}

int XScreen::GetHeight()
{
    return defaultScreen->height;
}