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

// Main function
int main()
{
	SandboxApp *app = new SandboxApp();
	app->run_application();

	delete app;
}