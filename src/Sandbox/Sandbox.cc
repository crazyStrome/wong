#include <Wong.h>

class Sandbox : public Wong::Application
{
private:
public:
    Sandbox()
    {
    }
    ~Sandbox()
    {
    }
};

Wong::Application *Wong::CreateApplication()
{
    return new Sandbox();
}