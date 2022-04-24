workspace "Kale-Engine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "Kale"
	location "Kale"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
		
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		runtime "Release"
		systemversion "latest"
		

		defines 
		{
			"KL_PLATFORM_WINDOWS",
			"KL_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "KL_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "KL_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "KL_DIST"
		optimize "On"
		
		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Kale/vendor/spdlog/include",
		"Kale/src"
	}
	
	links
	{
		"Kale"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines 
		{
			"KL_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "KL_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "KL_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "KL_DIST"
		optimize "On"
	
	