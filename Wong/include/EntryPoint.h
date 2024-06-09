#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H
extern Wong::Application *Wong::CreateApplication();

int main(int argc, char **argv)
{
    Wong::Log::Init();
    WG_CORE_INFO("Init log");
    auto app = Wong::CreateApplication();
    app->Run();
    delete app;
}

#endif