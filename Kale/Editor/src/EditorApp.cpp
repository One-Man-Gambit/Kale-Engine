
#include <Kale.h>

class EditorApp : public Kale::Application
{
public:
	EditorApp()
	{

	}

	~EditorApp()
	{

	}
};


Kale::Application* Kale::CreateApplication()
{
	return new EditorApp();
}