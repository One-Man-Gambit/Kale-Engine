#include "Debug.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Kale
{
	std::shared_ptr<spdlog::logger> Debug::s_Logger;

	void Debug::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_Logger = spdlog::stdout_color_mt("Kale");
		s_Logger->set_level(spdlog::level::trace);
	}
}