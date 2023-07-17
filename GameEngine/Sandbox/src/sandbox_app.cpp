/**
 * @file sandbox_app.cpp
 * @brief Main file for the sandbox application. This is the entry point of the
 * sandbox application. 
 * @author Carlos Salguero
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) - MIT License
 */

// C++ Standard Library
#include <memory>
 
// Project files
#include "game_engine.h"

// Sandbox application class
class SandboxApp : public GameEngine::Application
{
public:
	// Constructor
	SandboxApp()
	{
	}

	// Destructor
	~SandboxApp()
	{
	}
};

// Client defined functions
/**
 * @brief
 * Create the application object.
 * @return std::unique_ptr<GameEngine::Application> Pointer to the application
 * object.
 */
std::unique_ptr<GameEngine::Application> GameEngine::create_application()
{
	return std::make_unique<SandboxApp>();
}