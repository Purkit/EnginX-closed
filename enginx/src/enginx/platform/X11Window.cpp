#include <enginx/platform/X11Window.hpp>
#include <enginx/core/connection.hpp>
#include <enginx/core/screen.hpp>
#include <enginx/core/graphicsContext.hpp>
#include <enginx/input/keyboard.hpp>
#include <enginx/input/mouse.hpp>
#include <enginx/utility/logger.hpp>
#include <enginx/utility/asserts.hpp>
#include <enginx/event/Event.hpp>

#ifdef EX_USE_XORG


namespace enginx
{
    X11Window::X11Window(u32 width, u32 height, const std::string& title)
        : m_width(width), m_height(height), m_defaultWindowName(title) {}

    /* X11Window::X11Window(const ExWindowConfigInfo& window_configuration)
        : m_width(window_configuration.Width),
          m_height(window_configuration.Height),
          m_defaultWindowName(window_configuration.Title) {} */

    X11Window::~X11Window()
    {

    }

    void X11Window::CreateWindow()
    {
        XSetWindowAttributes windowAttribs = {};
        windowAttribs.border_pixel = BlackPixel(XConnection::connection, XScreen::defaultScreen_ID);
        windowAttribs.background_pixel = WhitePixel(XConnection::connection, XScreen::defaultScreen_ID);
        windowAttribs.override_redirect = True;
        windowAttribs.colormap = XCreateColormap(XConnection::connection, RootWindow(XConnection::connection, XScreen::defaultScreen_ID), GraphicsContext::m_visual->visual, AllocNone);
        windowAttribs.event_mask = ExposureMask | KeyPressMask | KeyReleaseMask | ButtonPressMask| ButtonReleaseMask | PointerMotionMask;        

        m_window = XCreateWindow(
            XConnection::connection, 
            RootWindow(XConnection::connection, XScreen::defaultScreen_ID),
            0, 0,
            m_width, m_height,
            0,
            GraphicsContext::m_visual->depth,
            InputOutput,
            GraphicsContext::m_visual->visual,
            CWBackPixel | CWColormap | CWBorderPixel | CWEventMask,
            &windowAttribs
        );
        
        XStoreName(XConnection::connection, m_window, m_defaultWindowName.c_str());       
       
        XClearWindow(XConnection::connection, m_window);
        //XMapRaised(XConnection::connection, m_window); // Show the window

        XFreeColormap(XConnection::connection, windowAttribs.colormap);

    }  // ! end of initWindow();

    void X11Window::postWindowCreation()
    {
        atomWMDeleteWindow = XInternAtom(XConnection::connection, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(XConnection::connection, m_window, &atomWMDeleteWindow, 1);

        motifWMHints = XInternAtom(XConnection::connection, "_MOTIF_WM_HINTS", true);
        wmState = XInternAtom(XConnection::connection, "_NET_WM_STATE", False);
        wmStateFullScreen = XInternAtom(XConnection::connection, "_NET_WM_STATE_FULLSCREEN", True);
    }  // ! end of postWindowCreating();

    void X11Window::OnUpdate()
    {

    }

    void X11Window::Initialize()
    {
        CreateWindow();
        postWindowCreation();
    }

    void X11Window::Show() const
    {
        XMapRaised(XConnection::connection, m_window);
    }

    void X11Window::Clear() const
    {
        XClearWindow(XConnection::connection, m_window);
    }

    void X11Window::SetTitle(const std::string& title) const
    {
        XStoreName(XConnection::connection, m_window, title.c_str());
    }

    void X11Window::Close()
    {
        m_shouldClose = true;
        XDestroyWindow(XConnection::connection, m_window);
    }

    void X11Window::PumpEvents()
    {
        while(XPending(XConnection::connection))
        {
            XNextEvent(XConnection::connection, &m_event_q);
            handle_event();
        }
    }

    void X11Window::WaitForEvents()
    {
        XNextEvent(XConnection::connection, &m_event_q);
        handle_event();
    }

    void X11Window::handle_event()
    {
        switch(m_event_q.type)
        {
            case KeyPress:
            {
                keysym = XLookupKeysym(&m_event_q.xkey, 0);
                ExKeyCode ex_key_code = Keyboard::getExKeyCodefromKeysym(keysym);
                KeyPressEvent kp_ev(ex_key_code, m_event_q.xkey.x, m_event_q.xkey.y);
                Event e;
                e.type = KEY_PRESS;
                e.key_press_event = kp_ev;
                EventSystem::Instance()->RegisterEvent(e);                     
                break;
            }

            case KeyRelease:
            {
                keysym = XLookupKeysym(&m_event_q.xkey, 0);
                ExKeyCode ex_key_code = Keyboard::getExKeyCodefromKeysym(keysym);
                KeyReleaseEvent kr_ev(ex_key_code, m_event_q.xkey.x, m_event_q.xkey.y);
                Event e;
                e.type = KEY_RELEASE;
                e.key_release_event = kr_ev;
                EventSystem::Instance()->RegisterEvent(e);                     
                break;
            }

            case ButtonPress:
            {
                if (m_event_q.xbutton.button == 1)
                {
                    MouseClickEvent click_ev(EX_LEFT_MOUSE_BUTTON, m_event_q.xbutton.x, m_event_q.xbutton.y);
                    Event e;
                    e.type = MOUSE_CLICK;
                    e.mouse_click_event = click_ev;
                    EventSystem::Instance()->RegisterEvent(e);
                }

                if (m_event_q.xbutton.button == 2)
                {
                    MouseClickEvent click_ev(EX_MIDDLE_MOUSE_BUTTON, m_event_q.xbutton.x, m_event_q.xbutton.y);
                    Event e;
                    e.type = MOUSE_CLICK;
                    e.mouse_click_event = click_ev;
                    EventSystem::Instance()->RegisterEvent(e);
                }

                if (m_event_q.xbutton.button == 3)
                {
                    MouseClickEvent click_ev(EX_RIGHT_MOUSE_BUTTON, m_event_q.xbutton.x, m_event_q.xbutton.y);
                    Event e;
                    e.type = MOUSE_CLICK;
                    e.mouse_click_event = click_ev;
                    EventSystem::Instance()->RegisterEvent(e);
                }
                
                if (m_event_q.xbutton.button == 4)
                {
                    MouseScrollEvent ms_scroll_ev(EX_MOUSE_SCROLL_UP, m_event_q.xbutton.x, m_event_q.xbutton.y);
                    Event e;
                    e.type = MOUSE_SCROLL;
                    e.mouse_scroll_event = ms_scroll_ev;
                    EventSystem::Instance()->RegisterEvent(e);
                }

                if (m_event_q.xbutton.button == 5)
                {
                    MouseScrollEvent ms_scroll_ev(EX_MOUSE_SCROLL_DOWN, m_event_q.xbutton.x, m_event_q.xbutton.y);
                    Event e;
                    e.type = MOUSE_SCROLL;
                    e.mouse_scroll_event = ms_scroll_ev;
                    EventSystem::Instance()->RegisterEvent(e);
                }

                break;
            }

            case ButtonRelease:
            {
                ExMouseButtonCode button = (ExMouseButtonCode)m_event_q.xbutton.button;
                MouseButtonReleaseEvent mb_rels_ev(button, m_event_q.xbutton.x, m_event_q.xbutton.y);
                Event e;
                e.type = MOUSE_RELEASE;
                e.mouse_button_release_event = mb_rels_ev;
                EventSystem::Instance()->RegisterEvent(e);
                break;
            }

            case MotionNotify:
            {
                MouseMoveEvent m_mv_ev((f32)m_event_q.xmotion.x, (f32)m_event_q.xmotion.y);
                Event e;
                e.type = MOUSE_MOVE;
                e.mouse_move_event = m_mv_ev;
                EventSystem::Instance()->RegisterEvent(e);
                break;
            }

            case Expose:  // * Window Resize Event
            {
                XWindowAttributes attribs;
                XGetWindowAttributes(XConnection::connection, m_window, &attribs);
                WindowResizeEvent win_resize_ev((u32)attribs.width, (u32)attribs.height);
                Event e;
                e.type = WINDOW_RESIZE;
                e.window_resize_event = win_resize_ev;
                EventSystem::Instance()->RegisterEvent(e);
                break;
            }

            case ClientMessage:                   
                if (m_event_q.xclient.data.l[0] == (long)atomWMDeleteWindow)                
                    m_shouldClose = true;
            break;

            case DestroyNotify:
                m_shouldClose = true;
            break;
        }

    } // !handle_event()

    void X11Window::MakeContextCurrent() const
    {
        glXMakeCurrent(XConnection::connection, m_window, GraphicsContext::m_context);

        #ifdef DEBUG_MODE
            DEBUG("GL Vendor: %s", glGetString(GL_VENDOR));
            DEBUG("GL Renderer: %s", glGetString(GL_RENDERER));
            DEBUG("GL Version: %s", glGetString(GL_VERSION));
        #endif
    }

    void X11Window::Present() const
    {
        // glXSwapIntervalEXT(XConnection::connection, m_window, 1);
        glXSwapBuffers(XConnection::connection, m_window);
    }

    void X11Window::Toggle_FullScreenMode()
    {
        XEvent fsEvent = {};
        fsEvent.xclient.type = ClientMessage;
        fsEvent.xclient.window = m_window;
        fsEvent.xclient.message_type = wmState;
        fsEvent.xclient.format = 32;
        fsEvent.xclient.data.l[0] = 2; // _NET_WM_STATE_TOGGLE
        fsEvent.xclient.data.l[1] = wmStateFullScreen;
        fsEvent.xclient.data.l[2] = 0;
        fsEvent.xclient.data.l[3] = 1;
        fsEvent.xclient.data.l[4] = 0;

        XSendEvent(XConnection::connection, DefaultRootWindow(XConnection::connection), False, SubstructureRedirectMask | SubstructureNotifyMask, &fsEvent);
        fullscreen = !fullscreen;
    }

    void X11Window::Toggle_BorderlessMode()
    {
        if (fullscreen) return;

        borderless = !borderless;

        struct MotifHints
        {
            unsigned long flags;
            unsigned long functions;
            unsigned long decorations;
            long inputMode;
            unsigned long status;
        };

        MotifHints hints = {};
        hints.flags = 2;
        hints.decorations = (borderless) ? 0 : 1;
        XChangeProperty(XConnection::connection, m_window, motifWMHints, motifWMHints, 32, PropModeReplace, (unsigned char*)&hints, 5);
        XMapWindow(XConnection::connection, m_window);
    }

    bool X11Window::shouldClose() const
    {
        return m_shouldClose;
    }

    u32 X11Window::GetWidth() const
    {
        // TODO: If the window is non-resizable then just return the initial width without retrieving the current width.
        XWindowAttributes attribs;
        XGetWindowAttributes(XConnection::connection, m_window, &attribs);
        return attribs.width;
    }

    u32 X11Window::GetHeight() const
    {
        // TODO: If the window is non-resizable then just return the initial height without retrieving the current height.  
        XWindowAttributes attribs;
        XGetWindowAttributes(XConnection::connection, m_window, &attribs);
        return attribs.height;
    }

    void X11Window::GetLocation(int& xpos, int& ypos) const
    {
        XWindowAttributes attribs;
        XGetWindowAttributes(XConnection::connection, m_window, &attribs);

        xpos = attribs.x;
        ypos = attribs.y;
    }
}

#endif // EX_USE_XORG