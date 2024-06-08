workspace "Wong"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Wong"
    location "Wong"
    kind "SharedLib"
    language "C++"
    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files {
        "%{prj.name}/src/**.cc"
    }
    
    includedirs {
        "%{prj.name}/include",
        "%{prj.name}/vendor/spdlog/include"
    }
    
    filter { "configurations:Debug" }
        defines "HZ_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "HZ_RELEASE"
        symbols "On"
    
    filter "configurations:Dist"
        defines "HZ_DIST"
        symbols "On"
    
    
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
        "Wong"
    }
    filter "configurations:Debug"
        defines "HZ_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "HZ_RELEASE"
        symbols "On"
    
    filter "configurations:Dist"
        defines "HZ_DIST"
        symbols "On"
    