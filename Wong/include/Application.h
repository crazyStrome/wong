#pragma once
#include "Events/Event.h"

namespace Wong
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    Application *CreateApplication();
}