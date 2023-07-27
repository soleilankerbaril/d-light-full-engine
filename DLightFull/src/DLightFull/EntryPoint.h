#pragma once

#ifdef DLF_PLATFORM_WINDOWS

extern DLF::Application* DLF::CreateApplication();

int main(int argc, char** argv)
{
	DLF::Log::Init();
	DLF_CORE_WARN("Initialized Log!");
	int a = 5;
	DLF_INFO("Hello! Var={0}", a);

	auto app = DLF::CreateApplication();
	app->Run();
	delete app;
}

#endif // DLF_PLATFORM_WINDOWS
