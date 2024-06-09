#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Wong
{
    class Log
    {
    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger()
        {
            return s_CoreLogger;
        }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger()
        {
            return s_ClientLogger;
        }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}
// Core log macros
#define WG_CORE_TRACE(...) ::Wong::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WG_CORE_INFO(...) ::Wong::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WG_CORE_WARN(...) ::Wong::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WG_CORE_ERROR(...) ::Wong::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WG_CORE_FATAL(...) ::Wong::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define WG_TRACE(...) ::Wong::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WG_INFO(...) ::Wong::Log::GetClientLogger()->info(__VA_ARGS__)
#define WG_WARN(...) ::Wong::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WG_ERROR(...) ::Wong::Log::GetClientLogger()->error(__VA_ARGS__)
#define WG_FATAL(...) ::Wong::Log::GetClientLogger()->critical(__VA_ARGS__)