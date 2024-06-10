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
Includedir["Glad"] = "%{wks.location}/Wong/vendor/Glad/include"
Includedir["ImGui"] = "%{wks.location}/Wong/vendor/ImGui"
Includedir["Wong"] = "%{wks.location}/Wong/include"
Includedir["LinuxPlatform"] = "%{wks.location}/Wong/Platform/include"

group "deps"
    include "Wong/vendor/GLFW"
    include "Wong/vendor/Glad"
    include "Wong/vendor/ImGui"

group "engine"
    include "Wong"
    
group "app"
    include "Sandbox" 