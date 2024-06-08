#pragma once

extern Wong::Application *Wong::CreateApplication();

int main(int argc, char **argv)
{
    auto app = Wong::CreateApplication();
    app->Run();
    delete app;
}