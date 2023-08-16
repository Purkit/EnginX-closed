#ifndef X_SCREEN_HPP
#define X_SCREEN_HPP

#include <X11/Xlib.h>

class XScreen
{
    public:
        static Screen* defaultScreen;
        static int defaultScreen_ID;
    
    public:
        static void GetDefaultScreen();
        static void Release();
    
    public:
        int GetWidth();
        int GetHeight();
};

#endif // X_SCREEN_HPP