project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.cc"
    }
    
    includedirs {
        "%{Includedir.Wong}",
        "%{Includedir.spdlog}",
        "%{Includedir.glm}",
        "%{Includedir.ImGui}",
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
        runtime "Debug"
    
    filter "configurations:Release"
        defines "WG_RELEASE"
        symbols "On"
        runtime "Release"
    
    filter "configurations:Dist"
        defines "WG_DIST"
        symbols "On"
        runtime "Release"
        
	filter "system:linux" 
        defines "WG_PLATFORM_LINUX"
        includedirs {
        }
    