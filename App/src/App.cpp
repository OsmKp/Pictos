#include "Core.h"

#include "Pictos/Core/EntryPoint.h"

#include "SampleLayer.h"

class App : public Pictos::Application
{
public:
	App() {
		PushLayer(new SampleLayer());
	}
	~App() override = default;
};

Pictos::Application* Pictos::CreateApplication() {
	return new App();
}