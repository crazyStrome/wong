#include "Wong.h"
#include <iostream>

namespace Wong
{
    Application::Application()
    {
    }
    Application::~Application()
    {
    }
    void Application::Run()
    {
        auto we = WindowResizeEvent(1200, 720);
        Event &e = we;
        WG_TRACE("Init event");
        WG_TRACE(e);
        while (true)
        {
        }
    }
}