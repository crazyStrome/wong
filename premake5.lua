workspace "Wong"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

Includedir = {}
Includedir["GLFW"] = "%{wks.location}/Wong/vendor/GLFW/include"
Includedir["spdlog"] = "%{wks.location}/Wong/vendor/spdlog/include"
Includedir["Wong"] = "%{wks.location}/Wong/include"
Includedir["LinuxPlatform"] = "%{wks.location}/Wong/Platform/include"

group "deps"
    include "Wong/vendor/GLFW"

group "engine"
    include "Wong"
    
group "app"
    include "Sandbox" 