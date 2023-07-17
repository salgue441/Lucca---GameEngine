/**
 * @file application.h
 * @brief Application class for the engine API. This class is
 * the entry point of the engine.
 * @author Carlos Salguero
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) - MIT License
 * 
 */

#ifndef APPLICATION_H
#define APPLICATION_H

// Project files
#include "../preprocessor/preprocessor.h"

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
		void run_application();
	};

#endif //! APPLICATION_H
} // namespace GameEngine