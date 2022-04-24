
#include <Kale.h>

class Sandbox : public Kale::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


Kale::Application* Kale::CreateApplication()
{
	return new Sandbox();
}