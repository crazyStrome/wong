#pragma once

#include "Layer.h"
#include "Events/MouseEvent.h"
#include "Events/KeyEvent.h"
#include "Events/ApplicationEvent.h"

namespace Wong
{
    struct MouseButtonPressedEvent;

    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event &event) override;

    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent &event);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &event);
        bool OnMouseMovedEvent(MouseMovedEvent &event);
        bool OnMouseScrolledEvent(MouseScrolledEvent &event);

        bool OnKeyPressedEvent(KeyPressEvent &event);
        bool OnKeyReleasedEvent(KeyReleasedEvent &event);
        bool OnKeyTypedEvent(KeyTypedEvent &event);
        bool OnWindowResizeEvent(WindowResizeEvent &event);

        float m_Time = 0.0f;
    };
}