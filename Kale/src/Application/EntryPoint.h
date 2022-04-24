#pragma once

#include "spdlog/spdlog.h"


#ifdef KL_PLATFORM_WINDOWS

extern Kale::Application* Kale::CreateApplication();

int main(int argc, char** argv)
{
	Kale::Debug::Init();
	Kale::Debug::Log("Trace Example");
	Kale::Debug::LogInfo("Info Example");	
	Kale::Debug::LogWarning("Warning Example");
	Kale::Debug::LogError("Error Example");
	Kale::Debug::LogCritical("Critical Example");


	auto app = Kale::CreateApplication();
	app->Run();
	delete app;
}

#endif 