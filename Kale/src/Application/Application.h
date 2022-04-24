#pragma once

#include "Kale/Core.h"

namespace Kale
{
	class KALE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	// To be defined in client.
	Application* CreateApplication();
}