#include "Window.h"

#ifdef WG_PLATFORM_LINUX
#include "LinuxWindow.h"
#endif

namespace Wong
{
    Window *Window::Create(const WindowProps &props)
    {
#ifdef WG_PLATFORM_LINUX
        return new LinuxWindow(props);
#else
        WG_CORE_ASSERT(false, "Unknown platform");
        return nullptr;
#endif
    }
}