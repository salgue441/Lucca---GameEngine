/**
 * @file entry_point.h	
 * @brief Contains the entry point of the game engine.
 * @author Carlos Salguero
 * @version 1.0
 * @date 2023-07-16
 * 
 * @copyright Copyright (c) - MIT License
 * 
 */

#pragma once

// C++ Standard Library
#include <memory>

// Preprocessors
#ifdef GE_PLATFORM_WINDOWS

// Extern functions
extern std::unique_ptr<GameEngine::Application> GameEngine::create_application();

/**
 * @brief
 * Main entry point of the game engine.
 * @param argc Number of arguments.
 * @param argv Arguments.
 * @return int Exit code.
 */
int	main(int argc, char** argv)
{
	auto app = GameEngine::create_application();
	app->run();
}

#endif //! GE_PLATFORM_WINDOWS