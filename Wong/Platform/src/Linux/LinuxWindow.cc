#include "Linux/LinuxWindow.h"
#include <Core.h>
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

#include "GLFW/glfw3.h"
#include "glad/glad.h"

namespace Wong
{
    static bool s_GLFWInitialized = false;
    static void GLFWErrorCallback(int error, const char *desc)
    {
        WG_CORE_ERROR("GLFW Error {0}, desc: {1}", error, desc);
    }
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
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }
        m_Window = glfwCreateWindow(int(props.Width), int(props.Height), props.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);

        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        WG_CORE_ASSERT(status, "Faild to iniliaze glad!");

        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        // Set glfw callback
        glfwSetWindowSizeCallback(m_Window,
                                  [](GLFWwindow *window, int width, int height)
                                  { 
                                    WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window); 
                                    data.Width = width;
                                    data.Height = height;
                                    WindowResizeEvent event(width, height);
                                    data.EventCallback(event); });
        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window)
                                   {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event); });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
                           {
                               WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                               switch (action)
                               {
                               case GLFW_PRESS:
                               {
                                    KeyPressEvent event(key, 0);
                                    data.EventCallback(event);
                                    break;                                
                               }
                               case GLFW_RELEASE:
                               {
                                    KeyReleasedEvent event(key);
                                    data.EventCallback(event);
                                    break;
                               }
                               case GLFW_REPEAT:
                               {
                                    KeyPressEvent event(key, 1);
                                    data.EventCallback(event);
                                    break;
                               }
                         } });
        glfwSetCharCallback(m_Window, [](GLFWwindow *window, unsigned int codepoint)
                            {
                                WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                                KeyTypedEvent event(codepoint);
                                data.EventCallback(event); });

        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods)
                                   { 
                                    WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window); 
                                   switch (action)
                                   {
                                   case GLFW_PRESS:
                                   {
                                        MouseButtonPressedEvent event(button);
                                        data.EventCallback(event);
                                        break;                                   
                                   }
                                   case GLFW_RELEASE:
                                   {
                                        MouseButtonReleasedEvent event(button);
                                        data.EventCallback(event);
                                        break;
                                   }
                                   } });
        glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xoffset, double yoffset)
                              {
                                  WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                                  MouseScrolledEvent event((float)xoffset, (float)yoffset);
                                  data.EventCallback(event); });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double xpos, double ypos)
                                 {
                                  WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                                  MouseMovedEvent event((float)xpos, (float)ypos);
                                  data.EventCallback(event); });
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
    void *LinuxWindow::GetNativeWindow() const
    {
        return m_Window;
    }
}
