#pragma once

#ifdef DLF_PLATFORM_WINDOWS
	#ifdef DLF_BUILD_DLL
		#define DLF_API __declspec(dllexport)
	#else
		#define DLF_API __declspec(dllimport)
	#endif
#else
	#error D-Light-Full Engine only supports Windows!
#endif