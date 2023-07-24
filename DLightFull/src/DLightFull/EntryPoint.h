#pragma once

#ifdef DLF_PLATFORM_WINDOWS

extern DLF::Application* DLF::CreateApplication();

int main(int argc, char** argv)
{
	auto app = DLF::CreateApplication();
	app->Run();
	delete app;
}

#endif // DLF_PLATFORM_WINDOWS
