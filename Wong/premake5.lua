project "Wong"
    kind "SharedLib"
    language "C++"
    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "wgpch.h"
    pchsource "include/wgpch.h"
    
    files {
        "src/**.cc",
        "Platform/src/OpenGL/*.cc",
    }
    
    includedirs {
        "include",
        "%{Includedir.spdlog}",
        "%{Includedir.GLFW}",
        "%{Includedir.Glad}",
        "%{Includedir.ImGui}",
    }

    links {
        "GLFW",
        "GL",
        "Glad",
        "ImGui",
    }
    
    filter { "configurations:Debug" }
        defines {
            "WG_ENABLE_ASSERTS",
            "WG_DEBUG"
        }
        symbols "On"
    
    filter "configurations:Release"
        defines "WG_RELEASE"
        symbols "On"
    
    filter "configurations:Dist"
        defines "WG_DIST"
        symbols "On"
        
    filter "system:linux" 
        includedirs {
            "%{Includedir.LinuxPlatform}"
        }
        files {
            "Platform/src/Linux/**.cc"
        }
        defines {
            "WG_PLATFORM_LINUX",
            "GLFW_INCLUDE_NONE",
        }
 