workspace "d-light-full-engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "DLightFull"
	location "DLightFull"
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
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DLF_PLATFORM_WINDOWS",
			"DLF_BUILD_DLL"
		}

		postbuildcommands
		{
			 ("{COPYDIR} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}
		

		filter "configurations:Debug"
			defines "DLF_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "DLF_RELEASE"
			symbols "On"

		filter "configurations:Dist"
			defines "DLF_DIST"
			symbols "On"

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
		"DLightFull/vendor/spdlog/include",
		"DLightFull/src"
	}

	links
	{
		"DLightFull"
	}
	
	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DLF_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DLF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DLF_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "DLF_DIST"
		symbols "On"
