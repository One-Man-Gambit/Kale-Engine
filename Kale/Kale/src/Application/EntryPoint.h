#pragma once

#ifdef KL_PLATFORM_WINDOWS

extern Kale::Application* Kale::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Kale::CreateApplication();
	app->Run();
	delete app;
}

#endif