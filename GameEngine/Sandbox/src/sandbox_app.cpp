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

// Entry point
/**
 * @brief
 * Entry point for the Game Engine.
 * 
 * @return int 
 */
int main(int argc, char** argv)
{
	std::unique_ptr<Sandbox> sandbox = std::make_unique<Sandbox>();
	sandbox->run();
}