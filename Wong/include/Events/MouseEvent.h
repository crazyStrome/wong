#pragma once

#include "Events/Event.h"

namespace Wong
{
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(const float x, const float y)
            : m_MouseX(x), m_MouseY(y) {}

        float GetX() const
        {
            return m_MouseX;
        }
        float GetY() const
        {
            return m_MouseY;
        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_MouseX, m_MouseY;
    };

    class MouseScrolledEvent : public Event
    {
    private:
        float m_XOffset, m_YOffset;

    public:
        MouseScrolledEvent(const float xOffset, const float yOffset)
            : m_XOffset(xOffset), m_YOffset(yOffset) {}

        float GetXOffset() const { return m_XOffset; }
        float GetYOffset() const { return m_YOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class MouseButtonEvent : public Event
    {
    protected:
        MouseButtonEvent(int button)
            : m_Button(button) {}
        int m_Button;

    public:
        int GetMouseButton() const { return m_Button; }
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton | EventCategoryInput)
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) {}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}

FORMAT_EVENT_FUNC(Wong::MouseButtonPressedEvent)
FORMAT_EVENT_FUNC(Wong::MouseScrolledEvent)