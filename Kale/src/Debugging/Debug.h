#pragma once

#include <memory>
#include <string>

#include "Kale/Core.h"
#include "spdlog/spdlog.h"


namespace Kale
{
	class KALE_API Debug
	{
	public:
		static void Init();

		static void Log(char* output) { s_Logger->trace(output); }
		static void LogInfo(char* output) { s_Logger->info(output); }		
		static void LogWarning(char* output) { s_Logger->warn(output); }
		static void LogError(char* output) { s_Logger->error(output); }
		static void LogCritical(char* output) { s_Logger->critical(output);  }

	private:
		static std::shared_ptr<spdlog::logger> s_Logger;

	};
}

