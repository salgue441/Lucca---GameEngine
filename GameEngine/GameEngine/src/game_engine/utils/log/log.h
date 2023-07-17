/**
 * @file log.h
 * @brief This file contains the declaration of the Log class.
 * @author Carlos Salguero
 * @version 1.0
 * @date 2023-07-17
 * 
 * @copyright Copyright (c) - MIT License
 * 
 */

#pragma once


// Project files
#include "../../core/preprocessor/preprocessor.h"

// Lib libraries
#include "spdlog/spdlog.h"

namespace GameEngine
{
	class GE_API Log
	{
	public:
		// Static methods
		static void init();
		inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return m_core_logger; }
		inline static std::shared_ptr<spdlog::logger>& get_client_logger() { return m_client_logger; }

	private:
		static std::shared_ptr<spdlog::logger> m_core_logger;
		static std::shared_ptr<spdlog::logger> m_client_logger;
	};
} // namespace GameEngine

// Macros for logging
#define GE_CORE_TRACE(...)		::GameEngine::Log::get_core_logger()->trace(__VA_ARGS__)
#define GE_CORE_WARN(...)		::GameEngine::Log::get_core_logger()->warn(__VA_ARGS__)
#define GE_CORE_INFO(...)		::GameEngine::Log::get_core_logger()->info(__VA_ARGS__)

#define GE_CORE_ERROR(...) 		::GameEngine::Log::get_core_logger()->error(__VA_ARGS__)
#define GE_CORE_FATAL(...)		::GameEngine::Log::get_core_logger()->fatal(__VA_ARGS__)

// Client log macros
#define GE_TRACE(...)			::GameEngine::Log::get_client_logger()->trace(__VA_ARGS__)
#define GE_WARN(...)			::GameEngine::Log::get_client_logger()->warn(__VA_ARGS__)
#define GE_INFO(...)			::GameEngine::Log::get_client_logger()->info(__VA_ARGS__)

#define GE_ERROR(...) 			::GameEngine::Log::get_client_logger()->error(__VA_ARGS__)
#define GE_FATAL(...)			::GameEngine::Log::get_client_logger()->fatal(__VA_ARGS__)