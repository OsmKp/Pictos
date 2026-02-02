#pragma once

#include "LayerStack.h"
#include "Event.h"
#include "Window.h"

#include <glm/glm.hpp>

#include <string>
#include <memory>
#include <vector>
#include <set>
#include <functional>


namespace Pictos
{

	struct ApplicationSpecification
	{
		std::string Name = "Application";
		WindowSpecification WindowSpec;
	};

	class Application
	{
	public:

		Application(const ApplicationSpecification spec = ApplicationSpecification());
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		//glm::vec2 GetFramebufferSize() const;

		static Application& Get();

	private:
		bool OnWindowClose(class WindowClosedEvent& e);

		ApplicationSpecification m_Specification;

		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Window> m_Window;

		static Application* s_Instance;

	};
	
	// To be defined in CLIENT
	Application* CreateApplication();
}