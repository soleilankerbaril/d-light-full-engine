#include <DLightFull.h>

class Sandbox : public DLF::Application
{
public:
	Sandbox() 
	{

	}

	~Sandbox()
	{

	}
};

DLF::Application* DLF::CreateApplication() 
{
	return new Sandbox();
}