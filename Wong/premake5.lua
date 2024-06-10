project "Wong"
    kind "SharedLib"
    language "C++"
    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")
    
    pchheader "wgpch.h"
    pchsource "include/wgpch.h"
    
    files {
        "src/**.cc",
        "src/vendor/glm/glm/**.hpp",
        "src/vendor/glm/glm/**.inl",
        "Platform/src/OpenGL/*.cc",
    }
    
    includedirs {
        "include",
        "%{Includedir.spdlog}",
        "%{Includedir.GLFW}",
        "%{Includedir.Glad}",
        "%{Includedir.ImGui}",
        "%{Includedir.glm}",
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
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines "WG_RELEASE"
        symbols "On"
        runtime "Release"
    
    filter "configurations:Dist"
        defines "WG_DIST"
        symbols "On"
        runtime "Release"
        
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
 