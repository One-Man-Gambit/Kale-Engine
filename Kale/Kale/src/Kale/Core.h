#pragma once

#ifdef KL_PLATFORM_WINDOWS
	#ifdef KL_BUILD_DLL
		#define KALE_API __declspec(dllexport)
	#else
		#define KALE_API __declspec(dllimport)
	#endif
#else
	#error Kale only supports Windows!
#endif