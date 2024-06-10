#pragma once
#include "Window.h"

struct GLFWwindow;

namespace Wong
{
    class LinuxWindow : public Window
    {
    private:
        GLFWwindow *m_Window;
        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;

        virtual void Init(const WindowProps &props);
        virtual void Shutdown();

    public:
        LinuxWindow(const WindowProps &props);
        virtual ~LinuxWindow();

        void OnUpdate() override;
        inline uint32_t GetWidth() const override { return m_Data.Width; }
        inline uint32_t GetHeight() const override { return m_Data.Height; }

        void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enable) override;
        bool IsVSync() const override;

        virtual void *GetNativeWindow() const override;
    };
}