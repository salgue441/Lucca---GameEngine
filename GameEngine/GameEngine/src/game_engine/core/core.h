/**
 * @file core.h
 * @brief Handles the ddl exports for the Game Engine.
 * @author Carlos Salguero
 * @version 1.0
 * @date 2023-07-14
 * 
 * @copyright Copyright (c) - MIT License
 * 
 */

#pragma once

/**
 * @brief
 * Defines the platform for the Game Engine. It defines the preprocessor
 */
#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL
		#define GE_API __declspec(dllexport)
	#else
		#define GE_API __declspec(dllimport)
	#endif //! GE_BUILD_DLL

#else 
	#error Game Engine only supports Windows!
#endif //! GE_BUILD_DLL