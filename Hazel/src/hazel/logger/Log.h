#pragma once
#include "hazel/core.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Hazel {

	class HAZEL_API Log 
	{
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:

		static void init();

		static std::shared_ptr<spdlog::logger>& getCoreLogger() {
			return s_CoreLogger;
		}

		static std::shared_ptr<spdlog::logger>& getClientLogger() {
			return s_ClientLogger;
		}

	};

}

// Call this macros for core logging.
#define CORE_LOG_TRACE(...)		::Hazel::Log::getCoreLogger()->trace(__VA_ARGS__)
#define CORE_LOG_INFO(...)		::Hazel::Log::getCoreLogger()->info(__VA_ARGS__)
#define CORE_LOG_WARN(...)		::Hazel::Log::getCoreLogger()->warn(__VA_ARGS__)
#define CORE_LOG_ERR(...)		::Hazel::Log::getCoreLogger()->error(__VA_ARGS__)
#define CORE_LOG_FATAL(...)		::Hazel::Log::getCoreLogger()->error(__VA_ARGS__)

// Call this macros for client logging.
#define CLIENT_LOG_TRACE(...)	::Hazel::Log::getClientLogger()->trace(__VA_ARGS__)
#define CLIENT_LOG_INFO(...)	::Hazel::Log::getClientLogger()->info(__VA_ARGS__)
#define CLIENT_LOG_WARN(...)	::Hazel::Log::getClientLogger()->warn(__VA_ARGS__)
#define CLIENT_LOG_ERR(...)		::Hazel::Log::getClientLogger()->error(__VA_ARGS__)
#define CLIENT_LOG_FATAL(...)	::Hazel::Log::getClientLogger()->error(__VA_ARGS__)

// Call this macros to assert statements.
#define CORE_ASSERT()