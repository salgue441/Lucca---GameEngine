/**
 * @file main.cpp
 * @brief Entry point for the Game Engine.
 * @author Carlos Salguero
 * @version 1.0
 * @date 2023-07-14
 * 
 * @copyright Copyright (c) - MIT License
 * 
 */
// C++ Standard LibraryJ
#include <memory>

// Project files
#include "core/sandbox/sandbox.h"

// Client defined functions
/**
 * @brief
 * Creates a new GameEngine :: Application object.
 * @return A unique pointer to a GameEngine :: Application object.
 */
std::unique_ptr<GameEngine::Application> GameEngine::create_application()
{
	return std::make_unique<Sandbox>();
}