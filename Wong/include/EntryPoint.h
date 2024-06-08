#pragma once

extern Wong::Application *Wong::CreateApplication();

int main(int argc, char **argv)
{
    Wong::Log::Init();
    Wong::Log::GetCoreLogger()->warn("Initial log");
    WONG_CORE_ERROR("heheh{0}", 10);
    auto app = Wong::CreateApplication();
    app->Run();
    delete app;
}