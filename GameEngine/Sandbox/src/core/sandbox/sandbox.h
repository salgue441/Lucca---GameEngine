/**
 * @file sandbox.h
 * @brief Declaration of the main class for the Sandbox application.
 * @author Carlos Salguero
 * @version 1.0
 * @date 2023-07-14
 * 
 * @copyright Copyright (c) - MIT License
 * 
*/

#ifndef SANDBOX_H
#define SANDBOX_H

// C++ Standard Library

// Project files
#include <game_engine.h>

class Sandbox : public GameEngine::Application
{
public:
	// Constructor
	Sandbox();

	// Destructor
	~Sandbox();
};

#endif //! SANDBOX_H