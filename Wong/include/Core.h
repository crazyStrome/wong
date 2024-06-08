#pragma once

#define BIT(x) (1 << x)

#ifdef WG_ENABLE_ASSERTS
#define WG_ASSERT(x, ...)                                   \
    {                                                       \
        if (!(x))                                           \
        {                                                   \
            WG_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __builtin_trap();                               \
        }                                                   \
    }

#define WG_CORE_ASSERT(x, ...)                                   \
    {                                                            \
        if (!(x))                                                \
        {                                                        \
            WG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __builtin_trap();                                    \
        }                                                        \
    }

#else
#define WG_ASSERT(x, ...)
#define WG_CORE_ASSERT(x, ...)
#endif