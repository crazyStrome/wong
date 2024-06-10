#include <Wong.h>
#include "imgui.h"

class ExapmleLayer : public Wong::Layer
{
public:
    ExapmleLayer()
        : Layer("Exapmle")
    {
    }

    void OnUpdate() override
    {
        if (Wong::Input::IsKeyPressed(WG_KEY_TAB))
        {
            WG_INFO("Tab key is pressed");
        }
    }
    void OnEvent(Wong::Event &event) override
    {
        // WG_TRACE("{0}", event);
    }
    void OnImGuiRender() override
    {
        ImGui::Begin("Exapmle layer");
        ImGui::Text("Hello exapmle layer");
        ImGui::End();
    }
};

class Sandbox : public Wong::Application
{
private:
public:
    Sandbox()
    {
        PushLayer(new ExapmleLayer());
    }
    ~Sandbox()
    {
    }
};

Wong::Application *Wong::CreateApplication()
{
    return new Sandbox();
}