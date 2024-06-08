workspace "Wong"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

Includedir = {}
Includedir["GLFW"] = "Wong/vendor/GLFW/include"
Includedir["spdlog"] = "Wong/vendor/spdlog/include"

include "Wong/vendor/GLFW"

project "Wong"
    location "Wong"
    kind "SharedLib"
    language "C++"
    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "wgpch.h"
    pchsource "Wong/include/wgpch.h"
    
    files {
        "%{prj.name}/src/**.cc"
    }
    
    includedirs {
        "%{prj.name}/include",
        "%{prj.name}/vendor/spdlog/include",
        "%{Includedir.GLFW}"
    }

    links {
        "GLFW",
        "GL",
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
            "Platform/Linux/include"
        }
        files {
            "Platform/Linux/src/**.cc"
        }
        defines {
            "WG_PLATFORM_LINUX"
        }
    
    
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.cc"
    }
    
    includedirs {
        "Wong/include",
        "Wong/vendor/spdlog/include"
    }
    
    links {
        "Wong",
    }
    filter "configurations:Debug"
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
        defines "WG_PLATFORM_LINUX"
        includedirs {
            "Platform/Linux/include"
        }
    