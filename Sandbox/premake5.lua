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
        }
    