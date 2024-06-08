#pragma once

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