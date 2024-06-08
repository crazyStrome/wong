
extern Wong::Application *Wong::CreateApplication();

int main(int argc, char **argv)
{
    Wong::Log::Init();
    WG_CORE_INFO("Init log");
    auto app = Wong::CreateApplication();
    app->Run();
    delete app;
}