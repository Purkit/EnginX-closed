#include <enginx/event/Event.hpp>

namespace enginx
{
    EventSystem *EventSystem::sInstance = NULL;

    KeyPressEvent::KeyPressEvent(ExKeyCode i_key_code, int x_ml, int y_ml)
        : key_code(i_key_code),
          x_mouse_position_during_key_event(x_ml),
          y_mouse_position_during_key_event(y_ml)
    {}

    KeyReleaseEvent::KeyReleaseEvent(ExKeyCode i_key_code, int x_ml, int y_ml)
        : key_code(i_key_code),
          x_mouse_position_during_key_event(x_ml),
          y_mouse_position_during_key_event(y_ml)
    {}

    MouseClickEvent::MouseClickEvent(ExMouseButtonCode mbc, f32 x_pos, f32 y_pos)
        : mouse_button_code(mbc),
          x_mouse_position_during_click(x_pos),
          y_mouse_position_during_click(y_pos)
    {}

    MouseButtonReleaseEvent::MouseButtonReleaseEvent(ExMouseButtonCode mbc, f32 x_pos, f32 y_pos)
        : mouse_button_code(mbc),
          x_mouse_position_during_release(x_pos),
          y_mouse_position_during_release(y_pos)
    {}

    MouseScrollEvent::MouseScrollEvent(Mouse_Scroll_direction scroll_dir, f32 x_pos, f32 y_pos)
        : scroll_direction(scroll_dir),
          x_mouse_position_during_scroll(x_pos),
          y_mouse_position_during_scroll(y_pos)
    {}

    MouseMoveEvent::MouseMoveEvent(f32 x_pos, f32 y_pos)
        : current_x_mouse_position(x_pos),
          current_y_mouse_position(y_pos)
    {}

    MouseMoveEvent::MouseMoveEvent(f32 x_pos, f32 y_pos, f32 rel_x, f32 rel_y)
        : current_x_mouse_position(x_pos),
          current_y_mouse_position(y_pos),
          relative_x_displacement(rel_x),
          relative_y_displacement(rel_y)
    {}

    WindowResizeEvent::WindowResizeEvent(u32 i_new_width, u32 i_new_height)
        : new_width(i_new_width),
          new_height(i_new_height)
    {}

    EventSystem *EventSystem::Instance()
    {
        static EventSystem evs;
        return &evs;
    }

    void EventSystem::RegisterEvent(Event &e)
    {
        m_Event_q.push(e);
    }

    Event EventSystem::NextEvent()
    {
        if (m_Event_q.size() > 0u)
        {
            Event e = m_Event_q.front();
            m_Event_q.pop();
            return e;
        }
        else
            return Event();
    }

    void EventSystem::AddListener(EventListener *listener)
    {
        m_map_of_listeners.insert(std::make_pair<EventListener *, EventListener *>(std::forward<EventListener *>(listener), std::forward<EventListener *>(listener)));
    }

    void EventSystem::RemoveListener(EventListener *listener)
    {
        std::map<EventListener *, EventListener *>::iterator it = m_map_of_listeners.find(listener);
        if (it != m_map_of_listeners.end())
        {
            m_map_of_listeners.erase(it);
        }
    }

    void EventSystem::ProcessAllQueuedEvent()
    {
        while (m_Event_q.size() > 0u)
        {
            Event event = NextEvent();
            switch (event.type)
            {
                case KEY_PRESS:
                {
                    std::map<EventListener *, EventListener *>::iterator it = m_map_of_listeners.begin();
                    while (it != m_map_of_listeners.end())
                    {
                        it->second->OnKeyPress(event.key_press_event.key_code);
                        ++it;
                    }
                    break;
                }

                case KEY_RELEASE:
                {
                    std::map<EventListener *, EventListener *>::iterator it = m_map_of_listeners.begin();
                    while (it != m_map_of_listeners.end())
                    {
                        it->second->OnKeyRelease(event.key_press_event.key_code);
                        ++it;
                    }
                    break;
                }

                case MOUSE_CLICK:
                {
                    std::map<EventListener *, EventListener *>::iterator it = m_map_of_listeners.begin();
                    while (it != m_map_of_listeners.end())
                    {
                        it->second->OnMouseClick(event.mouse_click_event.mouse_button_code);
                        ++it;
                    }
                    break;
                }

                case MOUSE_RELEASE:
                {
                    std::map<EventListener *, EventListener *>::iterator it = m_map_of_listeners.begin();
                    while (it != m_map_of_listeners.end())
                    {
                        it->second->OnMouseRelease(event.mouse_click_event.mouse_button_code);
                        ++it;
                    }
                    break;
                }

                case MOUSE_SCROLL:
                {
                    std::map<EventListener *, EventListener *>::iterator it = m_map_of_listeners.begin();
                    while (it != m_map_of_listeners.end())
                    {
                        it->second->OnMouseScroll(event.mouse_scroll_event.scroll_direction);
                        ++it;
                    }
                    break;
                }
                
                case MOUSE_MOVE:
                {
                    std::map<EventListener *, EventListener *>::iterator it = m_map_of_listeners.begin();
                    while (it != m_map_of_listeners.end())
                    {
                        it->second->OnMouseMove(event.mouse_move_event.current_x_mouse_position, event.mouse_move_event.current_y_mouse_position);
                        ++it;
                    }
                    break;
                }

                case WINDOW_RESIZE:
                {
                    std::map<EventListener *, EventListener *>::iterator it = m_map_of_listeners.begin();
                    while (it != m_map_of_listeners.end())
                    {
                        it->second->OnWindowResize(event.window_resize_event.new_width, event.window_resize_event.new_height);
                        ++it;
                    }
                    break;
                }
            }

        }
        
    }

    void EventSystem::ProcessEvents()
    {
        Event event = NextEvent();
        switch (event.type)
        {
            case KEY_PRESS:
            {
                std::map<EventListener *, EventListener *>::iterator it = m_map_of_listeners.begin();
                while (it != m_map_of_listeners.end())
                {
                    it->second->OnKeyPress(event.key_press_event.key_code);
                    ++it;
                }
                break;
            }

            case KEY_RELEASE:
            {
                std::map<EventListener *, EventListener *>::iterator it = m_map_of_listeners.begin();
                while (it != m_map_of_listeners.end())
                {
                    it->second->OnKeyRelease(event.key_press_event.key_code);
                    ++it;
                }
                break;
            }

            case MOUSE_CLICK:
            {
                std::map<EventListener *, EventListener *>::iterator it = m_map_of_listeners.begin();
                while (it != m_map_of_listeners.end())
                {
                    it->second->OnMouseClick(event.mouse_click_event.mouse_button_code);
                    ++it;
                }
                break;
            }

            case MOUSE_SCROLL:
            {
                std::map<EventListener *, EventListener *>::iterator it = m_map_of_listeners.begin();
                while (it != m_map_of_listeners.end())
                {
                    it->second->OnMouseScroll(event.mouse_scroll_event.scroll_direction);
                    ++it;
                }
                break;
            }

            case MOUSE_MOVE:
            {
                std::map<EventListener *, EventListener *>::iterator it = m_map_of_listeners.begin();
                while (it != m_map_of_listeners.end())
                {
                    it->second->OnMouseMove(event.mouse_move_event.current_x_mouse_position, event.mouse_move_event.current_y_mouse_position);
                    ++it;
                }
                break;
            }

        }

    }

}