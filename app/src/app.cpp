#include "../include/app.hpp"
#include <enginx/input/keyboard.hpp>
#include <enginx/input/mouse.hpp>
#include <enginx/event/Event.hpp>
#include <enginx/utility/logger.hpp>
#include <enginx/core/connection.hpp>
#include <enginx/core/screen.hpp>

#include <enginx/shader/shader.hpp>
#include <enginx/opengl/mesh/mesh.hpp>
#include <enginx/opengl/loader/loader.h>

#include <unistd.h>

namespace enginx
{
    void Application::Update()
    {
        EventSystem::Instance()->ProcessEvents();
    }

    void Application::OnKeyPress(ExKeyCode key_code)
    {
        if (key_code == EX_KEY_ESCAPE)
            m_window->Close();
        
        if (key_code == EX_KEY_F11)
            m_window->Toggle_FullScreenMode();

        if (key_code == EX_KEY_W)
            DEBUG("W Pressed.");
        
        if (key_code == EX_KEY_A)
            DEBUG("A Pressed.");
        
        if (key_code == EX_KEY_S)
            DEBUG("S Pressed.");
        
        if (key_code == EX_KEY_D)
            DEBUG("D Pressed.");
    }

    void Application::OnKeyRelease(ExKeyCode key_code)
    {
        if (key_code == EX_KEY_W)
            DEBUG("W Released.");
        
        if (key_code == EX_KEY_A)
            DEBUG("A Released.");
        
        if (key_code == EX_KEY_S)
            DEBUG("S Released.");
        
        if (key_code == EX_KEY_D)
            DEBUG("D Released.");
    }

    void Application::OnMouseClick(ExMouseButtonCode mouse_button)
    {
        if (mouse_button == EX_LEFT_MOUSE_BUTTON)
            DEBUG("LMB Pressed.");
        
        if (mouse_button == EX_MIDDLE_MOUSE_BUTTON)
            DEBUG("MMB Pressed.");
        
        if (mouse_button == EX_RIGHT_MOUSE_BUTTON)
            DEBUG("RMB Pressed.");
    }

    void Application::OnMouseRelease(ExMouseButtonCode mouse_button)
    {
        if (mouse_button == EX_LEFT_MOUSE_BUTTON)
            DEBUG("LMB Released.");
        
        if (mouse_button == EX_MIDDLE_MOUSE_BUTTON)
            DEBUG("MMB Released.");
        
        if (mouse_button == EX_RIGHT_MOUSE_BUTTON)
            DEBUG("RMB Released.");
    }

    void Application::OnMouseScroll(Mouse_Scroll_direction scroll_direction)
    {
        if (scroll_direction == EX_MOUSE_SCROLL_UP)
            DEBUG("Scrolled UP.");
        
        if (scroll_direction == EX_MOUSE_SCROLL_DOWN)
            DEBUG("Scrolled DOWN.");
    }

    void Application::OnMouseMove(f32 xpos, f32 ypos)
    {
        std::cout << "Current Cursor Position: (" << xpos << ", " << ypos << ")\n";
    }

    void Application::OnWindowResize(u32 new_width, u32 new_height)
    {
        // Change ViewPort accordingly.
    }    

    void Application::OnWindowGainFocus()
    {

    }

    void Application::OnWindowLoseFocus()
    {

    }

    void Application::OnWindowCreate()
    {

    }

    void Application::OnWindowClose()
    {

    }

    


    void Application::Initialize()
    {
        m_window = ExWindow::Create(1000, 800, "EnginX");
        GraphicsContext::Initialize();
        m_window->Initialize();
        m_window->Show();
        EventSystem::Instance()->AddListener(this);
        GraphicsContext::createGraphicsContext();
        m_window->MakeContextCurrent();
        Keyboard::Disable_AutoKeyRepeat();
    }

    void Application::Release()
    {
        GraphicsContext::Release();
    }


    void Application::Run()
    {
        MouseScrollEvent ms_scroll_ev(EX_MOUSE_SCROLL_UP, 0, 0);
        Event e;
        e.type = MOUSE_SCROLL;
        e.mouse_scroll_event = ms_scroll_ev;
        EventSystem::Instance()->RegisterEvent(e);

        LoadGL();
        
        Vertex triangle_data[] = 
        {
            Vertex{glm::vec3(-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f)},
            Vertex{glm::vec3(0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f)},
            Vertex{glm::vec3(0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f)}
        };
        
        Shader basicShader("../Assets/Shaders/basic.vert", "../Assets/Shaders/basic.frag");

        std::vector<Vertex> vertices_set1(triangle_data, triangle_data + sizeof(triangle_data) / sizeof(Vertex));

        Mesh triangle(vertices_set1);

        while (!m_window->shouldClose())
        {
            m_window->PumpEvents();

            //sleep(3);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

            triangle.Draw(basicShader);

            m_window->Present();            

            Update();
            // Render();
        }        
    }

}
