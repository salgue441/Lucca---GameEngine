/**
 * @file Application.h
 * @brief Main Application class for the Game Engine.
 * @author Carlos Salguero
 * @version 1.0
 * @date 2023-07-14
 * 
 * @copyright Copyright (c) - MIT License
 * 
 */

#pragma once

// C++ Standard Library
#include <memory>

// Project files
#include "../preprocessors/core/core.h"

namespace GameEngine
{
	class GE_API Application
	{
	public:
		// Constructor
		Application();

		// Destructor
		virtual ~Application();

		// Methods
		void run();
	};

	// Cliend defined functions
	std::unique_ptr<Application> create_application();

} // namespace GameEngine