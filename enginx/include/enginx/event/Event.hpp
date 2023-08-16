#ifndef EX_EVENT_HPP
#define EX_EVENT_HPP

#include "../defines.h"
#include "../input/keyboard.hpp"
#include "../input/mouse.hpp"

#include <queue>
#include <map>

#include "EventListener.hpp"

namespace enginx
{
    enum EventType
    {
        INVALID_EVENT,
        KEY_PRESS,
        KEY_RELEASE,
        MOUSE_CLICK,
        MOUSE_RELEASE,
        MOUSE_SCROLL,
        MOUSE_MOVE,
        WINDOW_CREATE,
        WINDOW_CLOSE,
        WINDOW_GAIN_FOCUS,
        WINDOW_LOSE_FOCUS,
        WINDOW_RESIZE
    };

    struct KeyPressEvent
    {
        EventType type = KEY_PRESS;
        KeyPressEvent(ExKeyCode i_key_code, int x_ml, int y_ml);
        ExKeyCode key_code;
        int x_mouse_position_during_key_event, y_mouse_position_during_key_event;
    };

    struct KeyReleaseEvent
    {
        EventType type = KEY_RELEASE;
        KeyReleaseEvent(ExKeyCode i_key_code, int x_ml, int y_ml);
        ExKeyCode key_code;
        int x_mouse_position_during_key_event, y_mouse_position_during_key_event;
    };

    struct MouseClickEvent
    {
        EventType type = MOUSE_CLICK;
        MouseClickEvent(ExMouseButtonCode mbc, f32 x_pos, f32 y_pos);
        ExMouseButtonCode mouse_button_code;
        f32 x_mouse_position_during_click, y_mouse_position_during_click;
    };

    struct MouseButtonReleaseEvent
    {
        EventType type = MOUSE_RELEASE;
        MouseButtonReleaseEvent(ExMouseButtonCode mbc, f32 x_pos, f32 y_pos);
        ExMouseButtonCode mouse_button_code;
        f32 x_mouse_position_during_release, y_mouse_position_during_release;
    };

    struct MouseScrollEvent
    {
        EventType type = MOUSE_SCROLL;
        MouseScrollEvent(Mouse_Scroll_direction scroll_dir, f32 x_pos, f32 y_pos);
        Mouse_Scroll_direction scroll_direction;
        f32 x_mouse_position_during_scroll, y_mouse_position_during_scroll;
    };

    struct MouseMoveEvent
    {
        EventType type = MOUSE_MOVE;
        MouseMoveEvent(f32 x_pos, f32 y_pos);
        MouseMoveEvent(f32 x_pos, f32 y_pos, f32 rel_x, f32 rel_y);
        f32 current_x_mouse_position, current_y_mouse_position;
        f32 relative_x_displacement, relative_y_displacement;
    };

    struct WindowCreateEvent
    {
        EventType type = WINDOW_CREATE;
    };

    struct WindowCloseEvent
    {
        EventType type = WINDOW_CLOSE;
    };

    struct WindowLoseFocusEvent
    {
        EventType type = WINDOW_LOSE_FOCUS;
    };

    struct WindowGainFocusEvent
    {
        EventType type = WINDOW_GAIN_FOCUS;
    };

    struct WindowResizeEvent
    {
        EventType type = WINDOW_RESIZE;
        WindowResizeEvent(u32 i_new_width, u32 i_new_height);
        u32 new_width, new_height;
    };

    struct Event
    {
        Event() : type(INVALID_EVENT) {}
        EventType type;
        union
        {
            KeyPressEvent key_press_event;
            KeyReleaseEvent key_release_event;
            MouseClickEvent mouse_click_event;
            MouseButtonReleaseEvent mouse_button_release_event;
            MouseScrollEvent mouse_scroll_event;
            MouseMoveEvent mouse_move_event;
            WindowResizeEvent window_resize_event;
            WindowGainFocusEvent window_gain_focus_event;
            WindowLoseFocusEvent window_lose_focus_event;
            WindowCreateEvent window_create_event;  // ? Not sure if this event realy needed
            WindowCloseEvent window_close_event;  // ? Not sure if this event realy needed
        };
    };

    class EventSystem
    {
        public:
            void ProcessAllQueuedEvent();  // TODO: Explain it. It processes all queued event all at once.
            void ProcessEvents();  // TODO: Explain it. It processes 1 single event in 1 call.
            void AddListener(EventListener* listener);
            void RemoveListener(EventListener* listener);
        
        public:
            void RegisterEvent(Event &e);
            Event NextEvent();
        
        public:
            static EventSystem* Instance();

        private:
            std::queue<Event> m_Event_q;
            std::map<EventListener* , EventListener* > m_map_of_listeners;
        
        private:
            static EventSystem* sInstance;
    };

} // namespace enginx

#endif // EX_EVENT_HPP