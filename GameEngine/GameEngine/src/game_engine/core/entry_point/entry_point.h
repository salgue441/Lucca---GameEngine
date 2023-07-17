/**
 * @file entry_point.h
 * @brief This file contains the entry point of the application. This is the
 * first file that is executed when the application is run. This file is
 * responsible for creating the application object and running it.
 * @author Carlos Salguero
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) - MIT License
 * 
 */

#pragma once

// C++ Standard Library
#include <memory>

#ifdef GE_PLATFORM_WINDOWS
	extern std::unique_ptr<GameEngine::Application> GameEngine::create_application();

/** 
 * @brief
 * Main function of the application. This is the entry point of the application.
 * @param argc Number of arguments passed to the application.
 * @param argv Array of arguments passed to the application.
 * @return int Exit code of the application.
 */
int main(int argc, char** argv)
{
	GameEngine::Log::init();
	GE_CORE_WARN("Initialized Log!");
	GE_INFO("Initialized Log!");

	auto app = GameEngine::create_application();
	app->run_application();

	return 0;
}

#endif // GE_PLATFORM_WINDOWS