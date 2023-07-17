/**
 * @file log.h
 * @brief This file contains the implementation of the Log class.
 * @author Carlos Salguero
 * @version 1.0
 * @date 2023-07-17
 *
 * @copyright Copyright (c) - MIT License
 *
 */

// Project files
#include "log.h"

// Lib libraries
#include "spdlog/sinks/stdout_color_sinks.h"

namespace GameEngine
{
	// Static methods
	std::shared_ptr<spdlog::logger> Log::m_core_logger;
	std::shared_ptr<spdlog::logger> Log::m_client_logger;

	/** 
	 * @brief
	 * Initializes the loggers.
	 */
	void Log::init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		m_core_logger = spdlog::stdout_color_mt("GAME_ENGINE");
		m_core_logger->set_level(spdlog::level::trace);

		m_client_logger = spdlog::stdout_color_mt("APP");
		m_client_logger->set_level(spdlog::level::trace);

	}
} // namespace GameEngine