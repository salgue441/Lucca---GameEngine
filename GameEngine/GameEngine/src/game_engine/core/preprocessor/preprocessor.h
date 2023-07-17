/**
 * @file preprocessor.h
 * @brief Preprocessor macros for the engine API.
 * @author Carlos Salguero
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) - MIT License
 * 
 */

#pragma once

// Macros
#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL
		#define GE_API __declspec(dllexport)
	#else
		#define GE_API __declspec(dllimport)
	#endif
#else
	#error Game Engine only supports Windows!
#endif