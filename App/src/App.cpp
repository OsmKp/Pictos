#include "Core.h"

#include "Pictos/Core/EntryPoint.h"

#include "SampleLayer.h"

class App : public Pictos::Application
{
public:
	App(const Pictos::ApplicationSpecification& spec ) {
		PushLayer(new SampleLayer());
	}
	~App() override = default;
};

Pictos::Application* Pictos::CreateApplication() {
	ApplicationSpecification spec;
	spec.Name = "AppyAppy";
	return new App(spec);
}