#pragma once

#include "Pictos/Core/PlatformDetection.h"
#include "Pictos/Core/Application.h"

#ifdef P_PLATFORM_WINDOWS

extern Pictos::Application* Pictos::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Pictos::CreateApplication();
	app->Run();
	delete app;
}
#endif