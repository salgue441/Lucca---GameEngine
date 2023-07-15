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

// Project files
#include "core/core.h"

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
} // namespace GameEngine