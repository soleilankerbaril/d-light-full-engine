#pragma once

#include <memory.h>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace DLF {

	class DLF_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define DLF_CORE_TRACE(...)		::DLF::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DLF_CORE_INFO(...)		::DLF::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DLF_CORE_WARN(...)		::DLF::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DLF_CORE_ERROR(...)		::DLF::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DLF_CORE_FATAL(...)		::DLF::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define DLF_TRACE(...)	::DLF::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DLF_INFO(...)	::DLF::Log::GetClientLogger()->info(__VA_ARGS__)
#define DLF_WARN(...)	::DLF::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DLF_ERROR(...)	::DLF::Log::GetClientLogger()->error(__VA_ARGS__)
#define DLF_FATAL(...)	::DLF::Log::GetClientLogger()->fatal(__VA_ARGS__)