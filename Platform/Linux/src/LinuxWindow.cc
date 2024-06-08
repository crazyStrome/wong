#include "LinuxWindow.h"
#include <Core.h>

namespace Wong
{
    static bool s_GLFWInitialized = false;
    void LinuxWindow::Init(const WindowProps &props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        WG_CORE_INFO("Create window {0} ({1}, {2})",
                     props.Title, props.Width, props.Height);
        if (!s_GLFWInitialized)
        {
            int success = glfwInit();
            WG_CORE_ASSERT(success, "Could not initialize GLFW");

            s_GLFWInitialized = true;
        }
        m_Window = glfwCreateWindow(int(props.Width), int(props.Height), props.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    void LinuxWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    LinuxWindow::LinuxWindow(const WindowProps &props)
    {
        Init(props);
    }

    LinuxWindow::~LinuxWindow()
    {
        Shutdown();
    }

    void LinuxWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void LinuxWindow::SetVSync(bool enable)
    {
        if (enable)
        {
            glfwSwapInterval(1);
        }
        else
        {
            glfwSwapInterval(0);
        }
        m_Data.VSync = enable;
    }

    bool LinuxWindow::IsVSync() const
    {
        return m_Data.VSync;
    }
}